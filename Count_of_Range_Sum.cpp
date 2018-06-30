class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param lower: a integer
     * @param upper: a integer
     * @return: return a integer
     */
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        // write your code here
        vector<int> PreSum(nums.size()+1, 0);
        for( int i=0; i<nums.size(); i++ )
            PreSum[i+1] = PreSum[i]+nums[i];
        return MergeCount( PreSum, 0, nums.size(), lower, upper );
    }
    int MergeCount(vector<int>& PreSum, int start, int end, int lower, int upper)
    {   
        int count = 0;
        int mid = (start+end)/2;
        vector<int> next_PreSum(end-start+1);
        
        if( start == end ) return 0;
        
        count += MergeCount(PreSum, start, mid, lower, upper);
        count += MergeCount(PreSum, mid+1, end, lower, upper);
        
        int l_idx = mid+1;
        int u_idx = mid+1;
        int new_idx = mid+1;
        for( int i=start, j=0; i<=mid; i++, j++ )
        {
            while( l_idx<=end && PreSum[l_idx]-PreSum[i]<lower ) l_idx++;
            while( u_idx<=end && PreSum[u_idx]-PreSum[i]<=upper ) u_idx++;
            count += (u_idx-l_idx);
            while( new_idx<=end && PreSum[new_idx]<PreSum[i]) {
                next_PreSum[j++] = PreSum[new_idx];
                new_idx++;
            }
            next_PreSum[j] = PreSum[i];
        }
        for( int i=new_idx; i<=end; i++ ) next_PreSum[i-start] = PreSum[i];
        for( int i=start; i<=end; i++ ) {
            PreSum[i] = next_PreSum[i-start]; 
        }
        return count;
    }
};
