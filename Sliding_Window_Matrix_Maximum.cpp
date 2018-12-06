class Solution {
public:
    /**
     * @param matrix: an integer array of n * m matrix
     * @param k: An integer
     * @return: the maximum number
     */
    int maxSlidingMatrix(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        if( m == 0 || k <= 0 ) return 0;
        int n = matrix[0].size();
        if( k > m || k > n ) return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = matrix[0][0];
        for( int i=1; i<m; i++ ) dp[i][0] = dp[i-1][0] + matrix[i][0];
        for( int j=1; j<n; j++ ) dp[0][j] = dp[0][j-1] + matrix[0][j];
        for( int i=1; i<m; i++ ) 
            for( int j=1; j<n; j++ ) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j];
            }
        // k-size window
        int ans = INT_MIN;
        for( int i = k-1; i < m; i++ ) 
        {
            for( int j = k-1; j < n; j++ ) 
            {
                int prev_row_k = ( i==k-1 ) ? 0 : dp[i-k][j];
                int prev_col_k = ( j==k-1 ) ? 0 : dp[i][j-k];
                int prev_both_k = ( i==k-1 || j==k-1 ) ? 0 : dp[i-k][j-k];
                if( dp[i][j]-prev_row_k-prev_col_k+prev_both_k > ans )
                    ans = dp[i][j]-prev_row_k-prev_col_k+prev_both_k;
            }
        }
        return ans==INT_MIN ? 0 : ans;
    }
};
