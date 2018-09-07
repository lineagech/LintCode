class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        for( int i=1; i<n; i++ )    
        {
            if( i % 2 == 1 && nums[i-1] > nums[i] ) // large
                swap( nums[i-1], nums[i] );
            else if( i % 2 == 0 && nums[i-1] < nums[i] )
                swap( nums[i-1], nums[i] );
        }
    }
};
