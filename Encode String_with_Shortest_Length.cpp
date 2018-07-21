class Solution {
public:
    /**
     * @param s: a string
     * @return: return a string
     */
    string encode(string &s) {
        // write your code here
        vector<vector<string>> dp(s.size(), vector<string>(s.size(), ""));
        for( int step = 1; step <= s.size(); step++ )
        {
            for( int i = 0; i+step-1 < s.size(); i++ )
            {
                int j = i + step - 1; // i...k and k+1...j
                dp[i][j] = s.substr(i, step);
                for( int k = i; k < j; k++ )
                {
                    string left = dp[i][k];
                    string right = dp[k+1][j];
                    if( left.size() + right.size() < dp[i][j].size() )
                    {
                        dp[i][j] = left+right;
                    }
                }
                
                string temp = s.substr(i, step);
                string replace = "";
                auto rep_pos = (temp+temp).find(temp, 1/*start from pos 1*/);
            
                if( rep_pos >= temp.size() ) 
                    replace = temp;
                else 
                    replace = to_string(temp.size()/rep_pos) + "[" + dp[i][i+rep_pos-1] +"]";
            
                if( replace.size() < dp[i][j].size() )
                    dp[i][j] = replace;
            }
        }
        return dp[0][s.size()-1];
    }
};
