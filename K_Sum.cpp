class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        int n = A.size();
        if( n == 0 || k == 0 || target < 0 ) return 0; 
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        vector<vector<int>> prev_dp(n+1, vector<int>(target+1, 0));
        sort(A.begin(), A.end());
        for( int m = 0; m <= n; m++ ) {
            prev_dp[m][0] = 1;
        }
        for( int i = 1; i <= k; i++ )
        {
            for( int j = 0; j <= target; j++ )
            {
                for( int m = 1; m <= n; m++ )
                {   
                    dp[m][j] = 0;
                    if( j >= A[m-1] ){
                        dp[m][j] += prev_dp[m-1][j-A[m-1]];
                    }
                    dp[m][j] += dp[m-1][j];
                }
            }
            prev_dp = dp;
        }

        return prev_dp[n][target];
    }
};
