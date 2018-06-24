class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<vector<int>> dp(A.size()+1, vector<int>(m+1,0));
            
        for(int i=1; i<=A.size(); i++)
        {
            int curr_size = A[i-1];
            for(int j=1; j<=m; j++)
            {
                if( curr_size <= j )
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-curr_size]+curr_size);
                else
                    dp[i][j] = dp[i-1][j];        
            }
        }
        return dp[A.size()][m];
    }
};
