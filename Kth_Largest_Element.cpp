class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int k, vector<int> &nums) {
        // write your code here
        return quick_select(nums, 0, nums.size()-1, k);
    }
    int quick_select( vector<int> &nums, int left, int right, int k )
    {
        int i = left, j = right;
        int pivot = nums[left];
        while( i <= j )
        {
            // find first element smaller than pivot
            while( i<=j && nums[i]>pivot )
                i++;
            // find first element greater than or pivot
            while( i<=j && nums[j]<pivot )
                j--;
            if(i <= j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        if( (j-left+1) >= k ) 
            return quick_select(nums, left, j, k);
        else if( (i-left) < k )
            return quick_select(nums, i, right, k-(i-left));
        return nums[j+1];
    }
};
