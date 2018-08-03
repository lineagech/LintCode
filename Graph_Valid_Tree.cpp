class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
     
    class Graph
    {
    public:
        Graph(int _n){ 
            nbr.resize(_n);
        }
        void add_edge( int a, int b )
        {
            nbr[a].push_back(b);
            nbr[b].push_back(a);
        }
        vector<vector<int>> nbr;
    };
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if( n <= 0 ) return false;
        Graph graph(n);
        for( auto edge : edges )
            graph.add_edge(edge[0], edge[1]);    
        
        vector<bool> visited(n, false);
        bool result = dfs(0, 0, n, graph, visited);
        for( auto v : visited ) result &= v;
        return result;
    }
    bool dfs(int parent_id, int id, int n, Graph& graph, vector<bool>& visited )
    {   
        visited[id]  = true;
        for( auto nbr_id : graph.nbr[id] )
        {   
            if( nbr_id == parent_id ) continue;
            if( visited[nbr_id] ) return false;
            if( !dfs(id, nbr_id, n, graph, visited) ) return false;
        }
        return true;
    }
    
};
