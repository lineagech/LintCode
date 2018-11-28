class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame2(vector<int> &A) {
        int n = A.size();
        int ans = INT_MAX;
        if( n <= 1 ) return 0;
        for( int i = 0; i < n-1; i++ ) A.push_back(A[i]);
        int new_n = n+n-1;
        vector<vector<int>> dp(new_n,vector<int>(new_n,0));
        vector<int> sum(new_n+1,0);
        for( int i = 1; i <= new_n; i++ ) sum[i]=sum[i-1]+A[i-1];
        for( int l = 2; l <= n; l++ ) 
        {
            for( int i = 0; i+l-1 < new_n; i++ )
            {
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                for( int k = i; k < j; k++ )
                {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
                dp[i][j] += sum[j+1]-sum[i];
                if( l == n ) ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
