class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        // dp[i][j] = dp[i-1][j-A[i]]
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for( int i = 0; i < n; i++ ) {
            for( int j = target; j >= 1; j-- ) {
                if( nums[i] <= j ) {
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};
