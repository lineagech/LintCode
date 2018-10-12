class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        vector<int> dp(target, 0);
        dp[0] = 1;
        for( int i = 1; i <= target; i++ ) {
            for( auto num : nums ) {
                if( i >= num ) dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};
