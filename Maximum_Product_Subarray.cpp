public class Solution {
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    public int maxProduct(int[] nums) {
        int[] currMax = new int[nums.length];
        int[] currMin = new int[nums.length];
        int ans = nums[0];
        
        currMax[0] = nums[0];
        currMin[0] = nums[0];
        for( int i=1; i<nums.length; i++ )
        {
            if( nums[i] >= 0 ) {
                currMax[i] = Math.max(currMax[i-1]*nums[i], nums[i]);
                currMin[i] = Math.min(currMin[i-1]*nums[i], nums[i]);
            }
            else {
                currMax[i] = Math.max(currMin[i-1]*nums[i], nums[i]);
                currMin[i] = Math.min(currMax[i-1]*nums[i], nums[i]);
            }
            ans = Math.max(ans, currMax[i]);
        }
        return ans;
    }
}
