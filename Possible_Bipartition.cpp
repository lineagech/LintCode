class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> graph(N);
        for( auto& d : dislikes )
        {
            graph[d[0]-1].push_back(d[1]-1); 
            graph[d[1]-1].push_back(d[0]-1);
        }
        vector<int> color(N, 0);
        for( int i = 0; i < N; i++ )
        {
            if( color[i]==0 && !dfs_check(i, 1, graph, color) ) return false;
        }
        return true;
    }
    bool dfs_check(int curr, int c, vector<vector<int>>& graph, vector<int>& color)
    {
        color[curr] = c; 
        for( auto n : graph[curr] )
        {
            if( color[n] == c ) return false;
            if( color[n] == 0 && !dfs_check(n, -c, graph, color) ) return false;
        }
        return true;
    }
};
