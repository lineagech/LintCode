class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     	There is a fence with n posts, each post can be painted with one of the k colors.
		You have to paint all the posts such that no more than two adjacent fence posts have the same color.
		Return the total number of ways you can paint the fence.

		Example
		Given n=3, k=2 return 6
     */
    int numWays(int n, int k) {
        // write your code here
        vector<int> dp(n, 0);
        if( n <= 0 || k <= 0 ) return 0;
        if( n == 1 ) return k;
        dp[0] = 1;
        dp[1] = k;
        for( int i = 2; i < n; i++ ) 
        {
        	dp[i] = (dp[i-1]+dp[i-2])*(k-1);
        }
        return dp[n-1]*k;
    }
};
