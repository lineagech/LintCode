class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if( m == 0 ) return {};
        int n = matrix[0].size();
        int maxSum = INT_MIN;
        vector<vector<int>> subRowSum(m, vector<int>(n, 0));
        
        for( int i = 0; i < m; i++ )
            for( int j = 0; j < n; j++ )
                if( i == 0 ) subRowSum[i][j] = matrix[i][j];
                else subRowSum[i][j] = matrix[i][j] + subRowSum[i-1][j];
        
        vector<int> left_top(2), right_bottom(2);
        for( int i = 0; i < m; i++ )
            for( int j = i; j < m; j++ )
            {
                vector<int> tmp(n);
                int currSum = 0;
                for( int k = 0; k < n; k++ )
                    tmp[k] = subRowSum[j][k] - ( (i==0) ? 0 : subRowSum[i-1][k] );
                
                unordered_map<int,int> hash;
                for( int k = 0; k < n; k++ )
                {
                    currSum += tmp[k];
                    if( currSum == 0 ) return { {i,0}, {j,k} };
                    if( hash.count(currSum) ) {
                        return { {i,hash[currSum]+1}, {j,k} };
                    }
                    hash[currSum] = k;
                }
            }
        return {{-1,-1}, {-1,-1}};
    }
    
};
