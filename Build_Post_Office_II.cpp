class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    class node
    {
    public:
    
        node(int _i, int _j){
            si = _i;
            sj = _j;
            distance = 0;
            count = 0;
        }
        int si;
        int sj;
        int distance;
        int count;
    };
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size();
        if( m == 0 ) return -1;
        int n = grid[0].size();
        int min_dist = INT_MAX;
        vector<vector<node>> record(m);
        for( int i = 0; i < m; i++ )
            for( int j = 0; j < n; j++ )
                record[i].push_back(node(i,j));
    
        int office_count = 0;
        for( int i = 0; i < m; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( grid[i][j] == 1 )
                {   
                    office_count++;
                    bfs(grid, record, i, j);
                }
            }
        }
        
        for( int i = 0; i < m; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( grid[i][j] == 0 &&  record[i][j].count == office_count )
                {
                    min_dist = min(min_dist, record[i][j].distance);
                }
            }
        }
        return (min_dist==INT_MAX) ? -1 : min_dist;
    }
    void bfs(vector<vector<int>> &grid, vector<vector<node>> &record, int office_i, int office_j)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        std::queue<node*> queue;
        queue.push( &record[office_i][office_j] );
        int step = 0;
        while( !queue.empty() )
        {
            step++;
            int queue_size = queue.size();
            for( int q = 0; q < queue_size; q++ )
            {
                node* curr = queue.front();
                queue.pop();
                for( int k = 0; k < 4; k++ )
                {
                    int next_i = curr->si + di[k];
                    int next_j = curr->sj + dj[k];
                    if( valid(grid, visited, next_i, next_j) )
                    {
                        record[next_i][next_j].count++;
                        record[next_i][next_j].distance += step;
                        visited[next_i][next_j] = true;
                        queue.push( &record[next_i][next_j] );
                    }
                }
            }
        }
    }
    bool valid( vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j )
    {
        return ( i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==0 && !visited[i][j] );
    }
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
};
