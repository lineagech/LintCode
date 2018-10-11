class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int n = A.size();
        if( n != V.size() ) return -1;
        
        vector<int> dp(m+1, 0);
        for( int i = 1; i <= m; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( i >= A[j] ) {
                    dp[i] = max(dp[i], dp[i-A[j]]+V[j]);
                }
            }
        }
        return dp[m];
    }
};
