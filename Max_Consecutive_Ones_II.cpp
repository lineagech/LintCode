class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int left = 0, right = 0; 
        int zero_pos;
        int ans = INT_MIN;
        
        for( ;right < n; right++ )
        {
            if( nums[right] == 0 )
            { 
                zero_pos = right;
                right = right+1;
                break;
            }
        }
        for( ; right < n; right++ )
        {
            if( nums[right] == 0 )
            { 
                ans = max(ans, right-left);
                left = zero_pos+1;
                zero_pos = right;
            }
        }
        ans = max(ans, right-left);
        return ans;
    }
};
