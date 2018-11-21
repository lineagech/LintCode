class Solution {
public:
    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
        m = matrix.size();
        if( m == 0 ) return 0;
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,1));
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if( dp[i][j]==1 ) dp[i][j] = helper(matrix, dp, i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int si, int sj)
    {   
        if( dp[si][sj] != 1 ) return dp[si][sj];
        for( int k = 0; k < 4; k++ )
        {
            int ni = si+di[k];
            int nj = sj+dj[k];
            if( ni>=0 && ni<m && nj>=0 && nj<n && matrix[si][sj]>matrix[ni][nj] )
            {
                dp[si][sj] = max(dp[si][sj], helper(matrix, dp, ni, nj)+1);
            }
        }
        return dp[si][sj]; 
    }
    int m;
    int n;
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
};
