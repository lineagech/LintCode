class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // write your code here
        if( nums.size() == 0 ) return vector<int>();
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, n);
        int max_len = 0, max_i = 0;
        for( int i = n-1; i >= 0; i-- )
        {
            for( int j = i+1; j < n; j++)
            {
                if( nums[j] % nums[i] == 0 && dp[i] < dp[j]+1 ) {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                    if( dp[i] > max_len ){
                        max_len = dp[i];
                        max_i = i;
                    }
                }
            }
        }
        vector<int> ans;
        for( int i = max_i; i < n; )
        {
            ans.push_back(nums[i]);
            i = parent[i];
        }
        return ans;
    }
};
