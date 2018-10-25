class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        if( n == 0 ) return 0;
        if( S[0]=='0' ) {
            dp[0][0] = 0;
            dp[1][0] = 1;
        }
        else {
            dp[0][0] = 1;
            dp[1][0] = 0;
        }
        for( int i = 1; i < n; i++ ) {
            if( S[i]=='0' ) {
                dp[0][i] = dp[0][i-1];
                dp[1][i] = min(dp[0][i-1],dp[1][i-1])+1;
            }
            else {
                dp[0][i] = dp[0][i-1]+1;
                dp[1][i] = min(dp[0][i-1],dp[1][i-1]);
            }
        }
        return min(dp[0][n-1], dp[1][n-1]);
    }
};
