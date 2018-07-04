class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        // write your code here
        // dp[i][]
        if( nums.size() == 0 ) return 0;
        if( nums.size() == 1 ) return nums[0];
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, 0));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        for( int i=1; i<nums.size()-1; i++ )
            dp[i-1][i+1] = nums[i-1]*nums[i]*nums[i+1];

        for( int len=4; len<=nums.size(); len++ )
        {
            for( int i=0; i<=nums.size()-len; i++ )
            {
                int j = i+(len-1);
                for( int k=i+1; k<j; k++ )
                {
                    dp[i][j] = max( dp[i][j], nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j] );
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};
