class Solution {
public:
    /**
     * @param n: an integer
     * @return: return an integer
     */
    int checkRecord(int n) {
        // write your code here
        int M = 1000000007;
        std::vector<long long> P_dp(n, 0);
        std::vector<long long> L_dp(n, 0);
        std::vector<long long> A_dp(n, 0);
        
        P_dp[0] = 1; P_dp[1] = 3;
        L_dp[0] = 1; L_dp[1] = 3;
        A_dp[0] = 1; A_dp[1] = 2; A_dp[2] = 4;
        for( int i=2; i<n; i++ )
        {
            P_dp[i] = (P_dp[i-1] + L_dp[i-1] + A_dp[i-1]) % M;
            L_dp[i] = (P_dp[i-1] + A_dp[i-1] + P_dp[i-2] + A_dp[i-2]) % M;
            if(i >= 3) A_dp[i] = (A_dp[i-1] + A_dp[i-2] + A_dp[i-3]) % M;
        }
        return (P_dp[n-1] + L_dp[n-1] + A_dp[n-1]) % M;
    }
    
};
