class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    class Graph
    {
    public:
        Graph()
        {
            
        }
        bool dfs_check( char source, char desti )
        {
            bool result = true;
            for( auto c : adj_node[desti] )
            {
                if( c == source ) return false;
                result &= dfs_check(source, c );
            }
            return result;
        }
        bool add_pair( char source, char desti )
        {
            if( !dfs_check(source, desti) ) return false;
            adj_node[source].push_back(desti);
            in_degree[desti-'a']++;
            if( in_degree.find(source-'a') == in_degree.end() )
            {
                in_degree[source-'a'] = 0;
            }
            return true;
        }
        std::unordered_map< char, vector<char> > adj_node;
        std::unordered_map< int, int > in_degree;
    };
    
    string alienOrder(vector<string> &words) {
        // Write your code here
        unordered_set<char> char_hash;
        Graph graph;
        queue<char> q, remaining;
        string ans, sorted_ans;
        
        set_remaining( words[0], char_hash, remaining );
        for( int i=1; i<words.size(); i++ )
        {   
            set_remaining( words[i], char_hash, remaining );
            vector<char> result = get_alpha_order(words[i-1], words[i]);
            if( result.size() != 0 )
            {
                if( !graph.add_pair( result[0], result[1] ) )
                {
                    return ans;
                }
            }
        }
        
        // find root
        for( auto it = graph.in_degree.begin(); it != graph.in_degree.end(); it++ )
        {
            if( it->second == 0 ) 
                q.push(it->first+'a');
        }
        
        while( !q.empty() )
        {
            char curr = q.front();
            q.pop();
            ans.push_back(curr);
            char_hash.erase(curr);
            for( int i=0; i<graph.adj_node[curr].size(); i++ )
            {
                char next = graph.adj_node[curr][i];
                graph.in_degree[next-'a']--;
                if( (graph.in_degree)[next-'a'] == 0 )
                {
                    q.push(next);
                }
            }
        }
        
        // process remaining
        for( int i=0; i<ans.size(); i++)
            char_hash.erase(ans[i]);
        int ans_idx = 0;
        for( auto it = char_hash.begin(); it != char_hash.end(); it++)
        {
            cout << (*it) << endl;
            while( ans_idx < ans.size() && *it > ans[ans_idx] )
            {
                ans_idx++;
            }
            ans.insert(ans.begin()+ans_idx, *it);
            ans_idx = 0;
        }
        
        return ans;
    }
    
    void set_remaining( string& str, unordered_set<char>& char_hash, queue<char>& remaining )
    {
        for( int j=0; j<str.size(); j++ )
        {
            if( char_hash.find(str[j]) == char_hash.end() )
            {
                remaining.push(str[j]);
                char_hash.insert(str[j]);
            }
        }
    }
    
    vector<char> get_alpha_order( string& s1, string& s2 )
    {
        vector<char> result(2);
        int s1_idx = 0, s2_idx = 0;
        while( s1_idx < s1.size() && s2_idx < s2.size() )
        {
            if( s1[s1_idx] == s2[s2_idx] ) {
                s1_idx++;
                s2_idx++;
            }
            else {
                result[0] = s1[s1_idx];
                result[1] = s2[s2_idx];
                return result;
            }
        }
        return result;
    }
    
    
};
