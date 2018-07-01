class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //
        vector<int> dp(s.size(), -1); //-1 means index 
        for( int j=1; j<s.size(); j++ )
        {
            int i = dp[j-1]; // matched index
            while( i>=0 && s[i+1]!=s[j] )
                i = dp[i];
            if( s[i+1] == s[j] )
                dp[j] = i+1;
        }
        int pattern_len = s.size()-(dp[s.size()-1]+1);

        return (dp[s.size()-1] != -1 ) && ((dp[s.size()-1]+1) % pattern_len == 0 );
    }
};
