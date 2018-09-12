class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<int,vector<string>> tree_map;
        for( auto word : words ) tree_map[word.size()].push_back(word);
        
        vector<char> lic_chars;
        for( auto c : licensePlate ) {
            char lower_c = tolower(c);
            if( lower_c >= 'a' && lower_c <= 'z' )
                lic_chars.push_back(lower_c);
        }
        
        for( auto t : tree_map )
        {   
            if( t.first < lic_chars.size() ) continue;
            
            for( auto node : t.second )
            {
                unordered_map<char,int> hash;
                bool valid = true;
                for( auto node_c : node )
                {
                    char lower_c = tolower(node_c);
                    if( lower_c >= 'a' && lower_c <= 'z' )
                        hash[lower_c]++;
                }   
                for( auto lic_c : lic_chars )
                {
                    hash[lic_c]--;
                    if( hash[lic_c] < 0 ) {
                        valid = false;
                        break;
                    }
                }
                if( valid ) return node;
            }
        }
        return "";
    }
};
