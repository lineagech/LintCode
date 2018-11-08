class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_map<string,string> root;
        for( int i = 0; i < A.size(); i++ )
        {   
            root[A[i]] = A[i];
            for( int j = 0; j < i; j++ )
            {
                if( isSimilar(A[i], A[j]) )
                {
                    string root_node1 = getRoot(root, A[j]);
                    string root_node2 = getRoot(root, A[i]);
                    root[root_node2] = root_node1;
                }
            }
        }
        int count = 0;
        for( auto it : root ){
            if( it.first == it.second ) count++;
        }
        return count;
    }
    
    bool isSimilar(string& a, string& b)
    {   
        int count = 0;
        for( int i = 0; i < a.size(); i++ )
        {
            if( a[i] != b[i] ) count++;
        }
        return count==2;
    }
    string getRoot(unordered_map<string,string>& root, string node)
    {
        while( root[node] != node )
            node = root[node];
        return node;
    }
};
