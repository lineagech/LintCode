class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        if( n != V.size() ) return -1;
        
        vector<int> dp(m+1, 0);
        for( int i = 0; i < n; i++ )
        {
            for( int j = m; j >= 0; j-- )
            {   
                if( j >= A[i] )
                    dp[j] = max(dp[j], dp[j-A[i]]+V[i]);
            }
        }
        return dp[m];
    }
};
