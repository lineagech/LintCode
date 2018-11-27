class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if( n <= 2 ) return true;

        vector<vector<int>> dp(n, vector<int>(n,0));
        for( int i = 0; i < n; i++ ) 
            dp[i][i] = values[i];
        for( int i = 0; i < n-1; i++ ) 
            dp[i][i+1] = max(values[i], values[i+1]);
        for( int l = 3; l <= n; l++ ) 
        {
            for( int i = 0; i+l <= n; i++ ) 
            {
                int j = i+l-1;
                dp[i][j] = max(values[i]+min(dp[i+2][j],+dp[i+1][j-1]), 
                                values[j]+min(dp[i+1][j-1],dp[i][j-2]));
            }
        }
        return dp[0][n-1]>dp[1][n-1] || dp[0][n-1]>dp[0][n-2];
    }
};
