public class Solution {
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    public long houseRobber(int[] A) {
        if( A.length <= 0 ) return 0;
        if( A.length == 1 ) return A[0];
        
        long prevOne = A[1];
        long prevTwo = A[0];
        for( int i = 2; i < A.length; i++ )
        {
            long tmp = prevOne;
            prevOne = Math.max(prevTwo+A[i], prevOne);
            prevTwo = tmp;
        }
        return Math.max(prevOne, prevTwo);
    }
}
