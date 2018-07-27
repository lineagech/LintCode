class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    #define RANGE(i,j,m,n) (i>=0 && i<m-1 && j>=0 && j<n-1)
    int trapRainWater(vector<vector<int>> &heights) {
        // write your code here
        int m = heights.size();
        if( m == 0 ) return 0;
        int n = heights[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> queue;
        vector<vector<bool>> visitied( m, vector<bool>(n, false) );
        int max_surface_height = INT_MIN;
        int ans = 0;
        
        for( int i=0; i<m; i++ )
        {
            for( int j=0; j<n; j++ )
            {
                if( i==0 || i==m-1 || j==0 || j==n-1  )
                {
                    queue.push( make_pair(heights[i][j], i*n+j) );
                    visitied[i][j] = true;
                }
            }
        }
        
        while( !queue.empty() )
        {
            pair<int,int> curr = queue.top();
            queue.pop();
            int curr_i = curr.second/n;
            int curr_j = curr.second%n;
            max_surface_height = max( max_surface_height, curr.first );
            for( int k = 0; k < 4; k++ )
            {
                int next_i = curr_i + di[k];
                int next_j = curr_j + dj[k];
                if( RANGE(next_i, next_j, m, n) && !visitied[next_i][next_j] )
                {   
                    if( max_surface_height > heights[next_i][next_j] )
                    {
                        ans += (max_surface_height - heights[next_i][next_j]);
                    }
                    queue.push( make_pair(heights[next_i][next_j], next_i*n+next_j) );
                    visitied[next_i][next_j] = true;
                }
            }
        }
        return ans;
        
    }
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
};
