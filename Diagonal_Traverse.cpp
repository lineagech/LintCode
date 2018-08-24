class Solution {
public:
    /**
     * @param matrix: a 2D array
     * @return: return a list of integers
     */
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        // write your code here
        vector<int> ans;
        const int UP = 1, DOWN = 2;
        int n = matrix.size(); 
        if( n == 0 ) return ans;
        int m = matrix[0].size();
        int dir = UP, curr_i = 0, curr_j = 0;
        for( int k = 0; k < n*m; k++ )
        {
            ans.push_back(matrix[curr_i][curr_j]);
            if( dir == UP )
            {
                if( curr_i - 1 < 0 )
                {
                    if( curr_j + 1 >= m ) curr_i++;
                    else curr_j++;
                    dir = DOWN;
                }
                else if( curr_j + 1 >= m )
                {
                    curr_i++;
                    dir = DOWN;
                }
                else
                {
                    curr_i--;
                    curr_j++;
                }
            }
            else if( dir == DOWN )
            {
                if( curr_j - 1 < 0 )
                {
                    if( curr_i + 1 >= n ) curr_j++;
                    else curr_i++;
                    dir = UP;
                }
                else if( curr_i + 1 >= n )
                {
                    curr_j++;
                    dir = UP;
                }
                else
                {
                    curr_i++;
                    curr_j--;
                }
            }
        }
        return ans;
    }
};
