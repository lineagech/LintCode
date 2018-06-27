class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> is_palindromic(s.size(), vector<bool>(s.size(), false));
        int ans = 0;
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        build_palindromic_table(s, is_palindromic);
        
        for( int i=0; i<s.size(); i++) 
        {
            for( int j=0; j<=i; j++ )
            {
                if( is_palindromic[j][i] ) ans++;  
            }
        }
        return ans;
    }
    void build_palindromic_table(string& s, vector<vector<bool>>& is_palindromic )
    {
        for( int len = 1; len <= s.size(); len++ )
        {
            for( int start_idx = 0; (start_idx+len-1) < s.size(); start_idx++ )
            {
               if( s[start_idx] == s[start_idx+len-1] )
               {
                    if( len == 1) 
                        is_palindromic[start_idx][start_idx+len-1] = true;
                    else if( len == 2 )  
                        is_palindromic[start_idx][start_idx+len-1] = true;
                    else if( len > 2 && is_palindromic[start_idx+1][start_idx+len-1-1] )
                        is_palindromic[start_idx][start_idx+len-1] = true;
               }
            }
        }
    }
};
