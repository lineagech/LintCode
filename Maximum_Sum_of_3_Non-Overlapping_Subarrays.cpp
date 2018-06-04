class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: three non-overlapping subarrays with maximum sum
     */
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        // Write your code here
        vector<vector<int>> dp(3, vector<int>(nums.size(), -1));
        vector<vector<int>> path(3, vector<int>(nums.size(), -1));
        vector<int> PreSum(nums.size(),0);
        vector<int> ans;
        
        if(nums.size()<3*k || k<=0) return ans;
        
        for(int i=0; i<nums.size(); i++) 
        {
            if(i == 0) PreSum[i] = nums[i];
            else PreSum[i] = PreSum[i-1] + nums[i];
        }
        for(int m=0; m<3; m++)
        {
            for(int j=m*k-1+k; j<nums.size(); j++)
            {
                int prev_term = (m==0) ? 0 : dp[m-1][j-k];
                int curr_PreSum = (j>=k) ? PreSum[j]-PreSum[j-k] : PreSum[j];
                if(j==0 || curr_PreSum+prev_term > dp[m][j-1])
                {
                    dp[m][j] = curr_PreSum+prev_term;
                    path[m][j] = j;
                }
                else
                {
                    dp[m][j] = dp[m][j-1];
                    path[m][j] = path[m][j-1];
                }
            }
        }
        
        int index_pos = nums.size()-1;
        for(int m=2; m>=0; m--)
        {
            int curr_pos = path[m][index_pos];
            ans.insert(ans.begin(),curr_pos-k+1);
            index_pos = curr_pos-k;
        }
        return ans;
    }
};
