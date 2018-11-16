class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        vector<vector<int>> dp(k+1, vector<int>(n+1,0));
        vector<int> pre_sum(n+1,0);
        for( int i=1; i<=n; i++ ) {
            pre_sum[i] = pre_sum[i-1]+pages[i-1];
            dp[1][i] = pre_sum[i];
        }
        for( int i=2; i<=k; i++ )  // k: number of people
        { 
            int p = 0;
            for( int j=1; j<=min(i,n); j++ ) // if number of people is less or equal to pages
                dp[i][j] = max(pages[j-1],dp[i][j-1]);
            for( int j=i+1; j<=n; j++ ) // if number of people is greater than pages
            {
                while( p<j && pre_sum[j]-pre_sum[p]>dp[i-1][p] ) p++;
                dp[i][j] = max(dp[i-1][p], pre_sum[j]-pre_sum[p]);
                if(p > 0) dp[i][j] = min(dp[i][j], pre_sum[j]-pre_sum[p-1]);
                //p--;
            }
        }
        return dp[k][n];
    }
};
