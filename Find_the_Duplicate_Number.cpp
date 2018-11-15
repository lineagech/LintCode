class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        if( nums.size() == 0 ) return 0;
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size()-1;
        while( start < end )
        {
            int mid = (start+end)/2;
            if( mid+1 > nums[mid] ){
                end = mid;
            }
            else {
                start = mid+1;
            }
        }
        return nums[start];
    }
};
