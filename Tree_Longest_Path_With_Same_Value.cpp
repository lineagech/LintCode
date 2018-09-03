class Solution {
public:
    /**
     * @param A: as indicated in the description
     * @param E: as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
     
    class Graph{
    public:
        Graph(int n) { 
            N = n; 
            nbr.resize(n+1);
            dp.resize(n+1);
        }
        void insert(int source, int destination)
        {
            nbr[source].push_back(destination);
            nbr[destination].push_back(source);
        }
        vector<vector<int>> nbr;
        vector<unordered_map<int,int>> dp; // look for one node's one label lobgest path distance from this node
        int N = 0;
    };
    
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        // write your code here
        int N = A.size();
        if( N == 0 ) return 0;
        if( E.size() % 2 != 0 ) return -1;
        
        Graph graph = Graph(N);
        for( int i=0; i<E.size(); i+=2 )
            graph.insert(E[i], E[i+1]);
        
        int longest_path = 0;
        for( int i=1; i<=N; i++ )
        {
            longest_path = max( longest_path, dfs_longest_path(graph, A, i, -1) );       
        }
        
        return longest_path;
    }
    
    int dfs_longest_path( Graph& graph, vector<int> &A, int target, int parent )
    {
        if( graph.dp[target].find(parent) != graph.dp[target].end() ) 
            return graph.dp[target][parent];
        int size = graph.nbr[target].size();
        int longest_path = 0;
        for( int i=0; i<graph.nbr[target].size(); i++ )
        {
            if( graph.nbr[target][i] != parent && A[graph.nbr[target][i]-1] == A[target-1] )
            {
                longest_path = max( longest_path, 
                                    dfs_longest_path(graph, A, graph.nbr[target][i], target)+1 );
            }
        }
        graph.dp[target][parent] = longest_path;
        return longest_path;
    }
};
