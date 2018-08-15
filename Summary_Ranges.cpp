class Solution {
public:
    /**
     * @param nums:  a sorted integer array without duplicates
     * @return: the summary of its ranges
     */
    vector<string> summaryRanges(vector<int> &nums) {
        // Write your code here
        vector<string> ans;
        int n = nums.size();
        if( n <= 0 ) return ans;
        if( n == 1 ) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int start = 0;
        int end;
        for( end=1; end<n; end++ )
        {
            if( nums[end]-1 > nums[end-1] ) // gap
            {
                string tmp = ( start == end-1 ) ? 
                             ( to_string(nums[start]) ) :
                             ( to_string(nums[start]) + "->" + to_string(nums[end-1]) );
                ans.push_back(tmp);
                start = end;
            }
        }
        if( start != n )
        {
            string tmp = ( start == end-1 ) ? 
                         ( to_string(nums[start]) ) :
                         ( to_string(nums[start]) + "->" + to_string(nums[end-1]) );
            ans.push_back(tmp);
        }
        return ans;
    }
};
