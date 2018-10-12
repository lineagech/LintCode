class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for( int i = 0; i < n; i++ ){
            for( int j = 1; j <= target; j++ ) {
                if(j >= nums[i]) {
                    if( nums[i] == j ) dp[j] += 1;
                    else dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};
