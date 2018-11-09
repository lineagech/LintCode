class Solution {
public:
    int knightDialer(int N) {
        if( N <= 0 ) return 0;
        long long ans = 0;
        long long mod = 1e9+7;
        vector<long long> dp(10, 1);
        vector<long long> prev_dp(10);
        for( int i = 0; i < N-1; i++ )
        {   
            prev_dp = dp;
            for(int j = 0; j < 10; j++ )
            {
                dp[j] = 0;
                for( int k = 0; k < prev[j].size(); k++ )
                {
                    dp[j] += prev_dp[prev[j][k]];
                }
                dp[j] %= mod;
            }
        }
        for(auto num : dp) {
            ans += num;
            ans %= mod;
        }
        return ans;
    }
    vector<vector<int>> prev= { 
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
};
