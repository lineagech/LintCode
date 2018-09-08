class Solution {
public:
    struct PairHash
    {
        template<class T>
        std::size_t operator()(const std::pair<T,T>& p) const // must add const to be const function
        {
            auto h1 = std::hash<T>{}(p.first);
            auto h2 = std::hash<T>{}(p.second);
            return (h1^h2);
        }
    };
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        // write your code here
        int n = edges.size()+1;
        vector<int> root(n+1);
        vector<int> ans(2);
        for( int i = 0; i<=n; i++ ) 
            root[i] = i;
        for( int i=0; i<edges.size(); i++ )
        {
            vector<int> edge = edges[i];
            int source = edge[0];
            int desti = edge[1];
            //cerr << source << "," <<desti<<endl;
            if( !Union(root, source, desti) )
            {
                ans[0] = source;
                ans[1] = desti;
                return ans;
            }
        }
        return ans;
    }
    
    bool Union(vector<int>& root, int a, int b)
    {
        int root_a = Find(root, a);
        int root_b = Find(root, b);
        if( root_a != root_b )
        {
            root[root_b] = root_a;
            return true;
        }
        return false;
    }
    
    int Find (vector<int>& root, int a)
    {
        if( root[a] != a )
        {
            return (root[a]=Find(root, root[a]));
        }
        return a;
    }
        
};
