class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums 
     */
    int findMin(vector<int> &nums) {
        if(nums.size() == 0) return 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum/2;
        vector<int> dp(target+1, 0);
        
        for( auto num : nums ) {
            for( int i = target; i >= 1; i-- ){
                if( i >= num )
                    dp[i] = max(dp[i], dp[i-num]+num);
            }
        }
        int res = sum - dp[target];
        return abs(res-dp[target]);
    }
};
