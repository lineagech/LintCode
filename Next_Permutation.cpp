class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        vector<int> ans(nums.begin(), nums.end());
        int swap_index = -1, first_index;
        int n = nums.size();
        if( n == 0 ) return ans;
        for( int i = n-1; i >= 1; i-- ) 
        {
            if( nums[i] <= nums[i-1] ) continue;
            else {
                swap_index = i-1;
                break;
            }
        }
        for( int i = n-1; i > swap_index; i-- ) 
        {
            if( swap_index >= 0 && nums[i] > nums[swap_index] ) {
                first_index = i;
                break;
            }
        }
        if( swap_index >= 0 ) swap(ans[swap_index], ans[first_index]);
        reverse(ans.begin()+swap_index+1, ans.end());
        
        return ans;
    }
};
