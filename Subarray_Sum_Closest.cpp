public class Solution {
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    class myPair implements Comparable<myPair>{
        public int sum;
        public int index;
        
        @Override
        public int compareTo(myPair other)
        {
            return this.sum - other.sum;
        }
    } 
     
    public int[] subarraySumClosest(int[] nums) {
        myPair[] preSum = new myPair[nums.length+1];
        int[] tmpAns = {0,0};
        if( nums.length <= 1 ) return tmpAns;
        
        for( int i = 0; i < nums.length+1; i++ )
        {   
            preSum[i] = new myPair();
            if( i == 0 ) preSum[i].sum = 0;
            else preSum[i].sum = preSum[i-1].sum+nums[i-1];
            preSum[i].index = i;
        }
     
        Arrays.sort(preSum);
        int minDiff = Integer.MAX_VALUE;
        int start = -1, end = -1;
        for( int i = 1; i < preSum.length; i++ )
        {
            if( minDiff > Math.abs( preSum[i].sum-preSum[i-1].sum ) )
            {
                minDiff = Math.abs( preSum[i].sum-preSum[i-1].sum ); 
                start = preSum[i-1].index;
                end = preSum[i].index;
            }
        }
        if( start > end ) {
            int tmp = start;
            start = end;
            end = tmp;
        } 
        int[] ans = {start, end-1};
        return ans;
    }
}
