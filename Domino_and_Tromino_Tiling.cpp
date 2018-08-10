class Solution {
public:
    int numTilings(int N) {
        std::vector<long long> dp(N+1,0);
        const int mod = 1e9 + 7;
        dp[0] = 0; 
        if( N == 0) return 0;
        dp[1] = 1; 
        if( N == 1) return 1;
        dp[2] = 2;
        if( N == 2) return 2;
        dp[3] = 5;
        for( int i=4; i<=N; i++)
        {
            dp[i] = (2*dp[i-1]+dp[i-3])%mod;
        }
        return (dp[N]%mod);
    }
};
