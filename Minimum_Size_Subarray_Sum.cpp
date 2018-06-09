class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int left = 0; // next element which will be substracted
        int right = 0; // next element which will be added
        int sum = 0;
        int min_len = INT_MAX;
        while(right < nums.size())
        {
            sum += nums[right++];
            while( sum >= s )
            {
                min_len = min(min_len, right-left);
                sum -= nums[left++];
            }
        }
        return (min_len==INT_MAX) ? -1 : min_len;
    }
};
