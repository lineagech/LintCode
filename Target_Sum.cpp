class Solution {
public:
    /**
     * @param nums: the given array
     * @param s: the given target
     * @return: the number of ways to assign symbols to make sum of integers equal to target S
     */
    int findTargetSumWays(vector<int> &nums, int s) {
        // Write your code here
        int n = nums.size();
        if( n == 0 ) return 0;
        vector<unordered_map<int,int>> dp(n, unordered_map<int,int>());
        dp[0][nums[0]] += 1;
        dp[0][-1*nums[0]] += 1;
        for( int i=1; i<n; i++ )
        {
            for( auto it : dp[i-1] )
            {
                int sum = it.first + nums[i];
                dp[i][sum] += it.second;
                sum = it.first - nums[i];
                dp[i][sum] += it.second;
            }
        }
        return dp[n-1][s];
    }
};
