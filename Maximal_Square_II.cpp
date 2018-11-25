class Solution {
public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if( m == 0 ) return 0;
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> z_width(m, vector<int>(n,0));
        vector<vector<int>> z_height(m, vector<int>(n,0));
        vector<vector<int>> diag(m, vector<int>(n,0));
        for( int i = 0; i < m; i++ ) 
        {
            for( int j= 0; j < n; j++ )
            {
                if( matrix[i][j] == 0 ) {
                    z_width[i][j] = (j!=0) ? z_width[i][j-1]+1 : 1;
                    z_height[i][j] = (i!=0) ? z_height[i-1][j]+1 : 1;
                }
                else {
                    if( i == 0 || j == 0 ) 
                        diag[i][j]=1;
                    else if( matrix[i-1][j] == 1 || matrix[i][j-1] == 1 || matrix[i-1][j-1] == 0 ) 
                        diag[i][j]=1;
                    else 
                        diag[i][j] = min(diag[i-1][j-1], min(z_height[i-1][j],z_width[i][j-1]))+1;
                    ans = max(ans, diag[i][j]*diag[i][j]);
                }
            }
        }
        return ans;
    }
};
