class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here
        int m = grid.size();
        if( m == 0 ) return 0;
        int n = grid[0].size();
        vector<pair<int,int>> row_union(m*n); // row
        vector<pair<int,int>> col_union(m*n); // col
        
        for( int i=0; i<m; i++ )
            for( int j=0; j<n; j++ )
            {
                row_union[i*n+j].first = i*n+j;
                col_union[i*n+j].first = i*n+j;
                if( grid[i][j] == 'E' )
                {
                    row_union[i*n+j].second = 1;
                    col_union[i*n+j].second = 1;
                }
                else
                {
                    row_union[i*n+j].second = 0;
                    col_union[i*n+j].second = 0;
                }
            }
        
        for( int i=0; i<m; i++ )
        {
            for( int j=0; j<n; j++ )
            {
                if( grid[i][j] == '0' || grid[i][j] == 'E' )
                {   
                    
                    if( i-1>=0 && grid[i-1][j]!='W' )
                        Union( col_union, i*n+j, (i-1)*n+j );
                    if( i+1<m && grid[i+1][j]!='W' )
                        Union( col_union, i*n+j, (i+1)*n+j );
                    if( j-1>=0 && grid[i][j-1]!='W' )
                        Union( row_union, i*n+j, i*n+j-1 );
                    if( j+1<n && grid[i][j+1]!='W' )
                        Union( row_union, i*n+j, i*n+j+1 );
                }
            }
        }
        int ans = 0;
        for( int i=0; i<m; i++ )
            for( int j=0; j<n; j++ )
                if( grid[i][j]=='0' )
                {
                    int s_row = col_union[i*n+j].first;
                    int s_col = row_union[i*n+j].first;
                    ans = max( col_union[s_row].second + row_union[s_col].second, ans );
                }
        return ans;
    }
    
    int Union_find( vector<pair<int,int>>& num, int idx )
    {
        int next = idx;
        if( num[idx].first != idx )
        {
            next = num[idx].first;
        }
        else return idx;
        
        return ( num[idx].first = Union_find(num,next) );
    }
    
    void Union( vector<pair<int,int>>& num, int source, int target )
    {
        int s = Union_find(num, source);
        int t = Union_find(num, target);
        if( s != t )
        {
            num[t].first = s;
            num[s].second += num[t].second;
        }
    }
};
