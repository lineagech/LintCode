class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        // dp[i][j] -> i...j minimum score
        // dp[i][j] = min(dp[i+1][j]+A[i], dp[i][j-1]+A[j])
        int n = A.size();
        if( n == 0 ) return 0;
        vector<int> pre_sum(n+1,0);
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        
        for( int i=1; i<=n; i++ ) pre_sum[i] = pre_sum[i-1]+A[i-1];
        for( int i=0; i<n; i++ ) dp[i][i] = 0;
        for( int i=0; i<n-1; i++ ) dp[i][i+1] = A[i]+A[i+1];
        
        for( int len = 3; len <= n; len++ )
        {
            for( int start = 0; (start+len-1) < n; start++ )
            {
                int end = start + (len-1);
                for( int k = start; k < end; k++ )
                {   
                    int new_value = dp[start][k]+dp[k+1][end];
                    new_value += pre_sum[end+1]-pre_sum[start];
                    if( new_value < dp[start][end] )
                    {
                        dp[start][end] = new_value;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
