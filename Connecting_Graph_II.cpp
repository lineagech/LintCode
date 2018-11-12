class ConnectingGraph2 {
public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        root.resize(n+1);
        size.resize(n+1, 1);
        for( int i = 0; i <= n; i++ )
            root[i] = i;
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if( root_a != root_b )
        {
            root[root_a] = root_b;
            size[root_b] = size[root_a] + size[root_b];
            size[root_a] = 0;
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        int root_a = find_root(a);
        return size[root_a];
    }
    
private: 
    int find_root(int node)
    {
        return (root[node] == node) ? node : (root[node]=find_root(root[node]));
    }
    
    std::vector<int> root;
    std::vector<int> size;
};
