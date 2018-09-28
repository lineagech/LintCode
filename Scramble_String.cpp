class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        // write your code here
        int n = s1.size();
        if( s2.size() != n ) return false;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1,false)));
        
        // dp[x][y][k] = ( dp[x][y][i] && dp[x+i][y+i][k-i] ) 
        //            || ( dp[x][y+k-i][i] && dp[x+i][y][k-i] ) for k in 1 to k
        
        // dp[x][y][1] = 1 if s1[x]==s2[y]
        for( int x = 0; x < n; x++ )
            for( int y = 0; y < n; y++ )
                dp[x][y][1] = (s1[x] == s2[y]);
        
        for( int k = 2; k <= n; k++ )
        {
            for( int x = 0; x+k <= n; x++ )
            {   
                for( int y = 0; y+k <= n; y++ )
                {   
                    for( int i = 1; i < k; i++ )
                    {
                        dp[x][y][k] = dp[x][y][k] || (( dp[x][y][i] && dp[x+i][y+i][k-i] ) || 
                                      ( dp[x][y+k-i][i] && dp[x+i][y][k-i] ));
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
