class Solution {
public:
    int kSimilarity(string A, string B) {
        int step = 0;
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(A);
        visited.insert(A);
        while( !q.empty() )
        {
            int q_size = q.size();
            for( int i=0; i<q_size; i++)
            {
                string node = q.front();
                q.pop();
                if( node == B ) return step;
                vector<string> next_nodes = get_next(node, B);
                for( int j = 0; j < next_nodes.size(); j++ )
                {
                    if( visited.find( next_nodes[j] ) == visited.end() )
                    {   
                        visited.insert(next_nodes[j]);
                        q.push(next_nodes[j]);
                    }
                }
            }
            step++;
        }
        return step;
    }
    vector<string> get_next(string T, string B)
    {
        // find the first char which is different between T and B
        vector<string> ans;
        int diff_idx;
        for( diff_idx=0; diff_idx<T.size(); diff_idx++ )
            if( T[diff_idx] != B[diff_idx] ) break;

        for( int i=diff_idx+1; i<T.size(); i++ )
        {
            if( T[i] == B[diff_idx] ) 
            {
                string tmp = T;
                swap(tmp[diff_idx], tmp[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
