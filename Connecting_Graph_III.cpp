class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    ConnectingGraph3(int n)
    {
        for( int i = 1; i <= n; i++ )
            root[i] = i;
        size = n;
    }
    
    void connect(int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        
        if(root_a != root_b) 
        {
            root[find_root(a)] = find_root(b);
            size--;
        }
    }

    /**
     * @return: An integer
     */
    int query() {
        return size;
    }
    
    int find_root(int node)
    {
        return root[node]==node ? (node) : (root[node]=find_root(root[node]));   
    }
    
    unordered_map<int,int> root;
    int size = 0;
};
