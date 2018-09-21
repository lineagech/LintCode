class Solution {
public:
    int m;
    int n;
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        m = matrix.size();
        if( m == 0 ) return vector<pair<int,int>>();
        n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<pair<int,int>> ans;
        
        for( int j = 0; j < n; j++ ){
            dfs( matrix, pacific, INT_MIN, 0, j );
            dfs( matrix, atlantic, INT_MIN, m-1, j );
        }
        
        for( int i= 0; i < m; i++ ){
            dfs( matrix, pacific, INT_MIN, i, 0 );
            dfs( matrix, atlantic, INT_MIN, i, n-1 );
        }
        
        for( int i = 0; i < m; i++ )
            for( int j = 0; j < n; j++ )
                if( pacific[i][j] && atlantic[i][j] ) 
                    ans.push_back({i,j});
        
        return ans;
    }

    void dfs( vector<vector<int>> &matrix, vector<vector<bool>>& visited, int pre_height, int curr_i, int curr_j )
    {
        if( curr_i < 0 || curr_i >= m || curr_j < 0 || curr_j >= n 
        || visited[curr_i][curr_j] || pre_height > matrix[curr_i][curr_j] )
        {
            return;
        }
        visited[curr_i][curr_j] = true;
        
        dfs(matrix, visited, matrix[curr_i][curr_j], curr_i+1, curr_j);
        dfs(matrix, visited, matrix[curr_i][curr_j], curr_i-1, curr_j);
        dfs(matrix, visited, matrix[curr_i][curr_j], curr_i, curr_j+1);
        dfs(matrix, visited, matrix[curr_i][curr_j], curr_i, curr_j-1);
    }
};
