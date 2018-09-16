class Solution {
public:
    /**
     * @param matrix: a 0-1 matrix
     * @return: return a matrix
     */
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        // write your code here
        int m = matrix.size();
        if( m == 0 ) return vector<vector<int>>();
        int n = matrix[0].size();
        int step = 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> queue;
        
        for( int i = 0; i < m; i++ )
            for( int j = 0; j < n; j++ )
                if( matrix[i][j] == 0 ) {
                    queue.push(make_pair(i,j));
                }
        while( !queue.empty() )
        {   
            step++;
            int q_size = queue.size();
            for( int k = 0; k < q_size; k++ )
            {
                int q_i = queue.front().first;
                int q_j = queue.front().second;
                queue.pop();
                for( int d = 0; d < 4; d++ )
                {
                    int next_i = q_i + di[d];
                    int next_j = q_j + dj[d];
                    if( isValid(next_i, next_j, m, n, matrix, visited) )
                    {   
                        ans[next_i][next_j] = step;
                        visited[next_i][next_j] = true;
                        queue.push(make_pair(next_i,next_j));
                    }
                }
                
            }
        }
        return ans;
    }
    bool isValid( int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<bool>>& visited )
    {
        return ( i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] == 1 && !visited[i][j] );
    }
};
