class Solution {
public:
    /**
     * @param edges: List[List[int]]
     * @return: List[int]
     */
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        // write your code here
        int n = edges.size();
        vector<int> root(n+1);
        for( int i=0; i<=n; i++ ) root[i] = i;
        for( auto edge : edges )
        {
            if( !Union(root, edge[0], edge[1]) ) return edge;
        }
    }
    bool Union( vector<int>& root, int a, int b )
    {
        while( root[a] != a ) a = root[a];  
        while( root[b] != b ) b = root[b];  
        if( a != b ) {
            root[b] = a;
            return true;
        }
        return false;
    }
};
