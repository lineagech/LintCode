class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    class state{
    public:
        state(int _i, int _j, int _dir):pos_i(_i),pos_j(_j), dir(_dir){}
        int pos_i;
        int pos_j;
        int dir;
    };
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        int m = maze.size();
        if( m == 0 ) return false;
        int n = maze[0].size();
        queue<state> queue;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        if( maze[start[0]][start[1]] == 1 ) return false;
        if( maze[destination[0]][destination[1]] == 1 ) return false;
        
        queue.push( state(start[0], start[1], 0) );
        queue.push( state(start[0], start[1], 1) );
        queue.push( state(start[0], start[1], 2) );
        queue.push( state(start[0], start[1], 3) );
        visited[start[0]][start[1]] |= (1<<0) | (1<<1) | (1<<2) | (1<<3);
        
        while( !queue.empty() )
        {
            int q_size = queue.size();
            for( int k = 0; k < q_size; k++ )
            {
                state curr = queue.front();
                queue.pop();
                int next_i = curr.pos_i + di[curr.dir];
                int next_j = curr.pos_j + dj[curr.dir];
                if( isValid(next_i, next_j, maze, visited, curr.dir) )
                {   
                    //if( next_i == destination[0] && next_j == destination[1] ) return true;
                    queue.push(state(next_i,next_j,curr.dir));
                    visited[next_i][next_j] |= (1<<curr.dir);
                }
                else
                {
                    if( next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || maze[next_i][next_j] == 1 )
                    {   
                        if( curr.pos_i == destination[0] && curr.pos_j == destination[1] ) return true;
                        for( int k = 0; k < 4; k++ )
                        {
                            if( curr.dir == k ) continue;
                            next_i = curr.pos_i + di[k];
                            next_j = curr.pos_j + dj[k];
                            if( isValid(next_i, next_j, maze, visited, k) )
                            {   
                                queue.push(state(next_i,next_j,k));
                                visited[curr.pos_i][curr.pos_j] |= (1<<k);
                                visited[next_i][next_j] |= (1<<k);
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
    bool isValid(int next_i, int next_j, vector<vector<int>> &maze, vector<vector<int>>& visited, int dir)
    {
        return (next_i>=0 && next_i<maze.size() && next_j>=0 && next_j<maze[0].size() && maze[next_i][next_j] == 0 && (visited[next_i][next_j] & (1<<dir))==0);
    }

    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
};
