class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        auto mid_it = nums.begin() + n/2;
        nth_element( nums.begin(), mid_it, nums.end() );
        int mid = *mid_it;
        
        // [1, 5, 1, 1, 6, 4]
        /* the nums[0] should be n/2-th element */
        #define S(i) ( nums[(i*2+1) % (n|1)] )
        /* From head to tail is descending oreder */
        int head = 0, tail = n-1, curr = 0;
        while( curr <= tail )
        {
            if( S(curr) > mid ) 
                swap( S(head++), S(curr++) );
            else if( S(curr) < mid )
                swap( S(curr), S(tail--) );
            else
                curr++;
        }
    }
};
