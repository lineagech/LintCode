class Solution {
public:
    /**
     * @param matrix: a 2D matrix
     * @param k: an integer
     * @return: the max sum of a rectangle in the matrix such that its sum is no larger than k
     */
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        // Write your code here
        int m = matrix.size();
        if( m == 0 ) return 0;
        int n = matrix[0].size();
        int ans = INT_MIN;
        
        for( int j = 0; j < n; j++ )
        {
            vector<int> PreSum(m,0);
            vector<int> sub_matrix(m,0);
            for( int l = j; l < n; l++ )
            {
                set<int> tree;
                PreSum[0] = matrix[0][l]; 
                for( int i=1; i<m; i++ ) PreSum[i] = PreSum[i-1] + matrix[i][l];
                tree.insert( 0 );
                for( int i=0; i<m; i++ )
                {
                    sub_matrix[i] += PreSum[i];
                    auto it =tree.lower_bound(sub_matrix[i]-k);
                    if( it != tree.end() )
                    {
                        ans = max( ans, sub_matrix[i]-(*it) );
                    }
                    tree.insert( sub_matrix[i] );
                }
            }
        }
        return ans;
    }
};
