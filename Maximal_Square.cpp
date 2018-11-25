class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if( m == 0 ) return 0;
        int n = matrix[0].size();
        vector<vector<int>> width(m, vector<int>(n,0));
        vector<vector<int>> height(m, vector<int>(n,0));
        vector<vector<int>> sq_len(m, vector<int>(n,0));
        int ans = 0;
        for( int i = 0; i < m; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( matrix[i][j] == 1 ) 
                {
                    width[i][j] = (j != 0) ? width[i][j-1]+1 : 1; 
                    height[i][j] = (i != 0) ? height[i-1][j]+1 : 1; 
                    if( i == 0 || j == 0 ) {
                        sq_len[i][j] = 1;
                    }
                    else{
                        int len = min(sq_len[i-1][j-1]+1, width[i][j-1]+1);
                        len = min(len, height[i-1][j]+1);
                        sq_len[i][j] = len;
                    }
                    ans = max( sq_len[i][j]*sq_len[i][j], ans );
                }
            }
        }

        return ans;
    }
};
