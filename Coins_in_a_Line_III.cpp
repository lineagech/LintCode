class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if( n <= 1 ) return true;
        vector<int> dp(n, 0);
        vector<int> sum(n+1, 0);
        for( int i = 1; i <= n; i++ ) {
            sum[i] = sum[i-1]+values[i-1];
            dp[i-1] = values[i-1];
        }
        for( int l = 2; l <= n; l++ ) 
        {
            int prev_dp = dp[n-l+1];
            for( int i = n-l; i >= 0; i-- )
            {
                int j = i+l-1;
                int tmp = dp[i];
                dp[i] = max( values[i]+(sum[j+1]-sum[i+1])-prev_dp, 
                             values[j]+(sum[j]-sum[i])-dp[i] );
                prev_dp = tmp;
            }
        }
        return (dp[0] > (sum[n]-dp[0])); 
    }
};
