ass Solution {
public:
    /**
     * @param formula: a string
     * @return: return a string
     */
    string countOfAtoms(string &formula) {
        // write your code here
        std::stack<unordered_map<string,int>> stack;
        unordered_map<string,int> hash;
        string ans;
        int formula_idx = 0;
        
        if( formula.size() == 0 ) return ans;
        
        while( formula_idx < formula.size() )
        {
            if( formula[formula_idx] == '(' )
            {
                stack.push( hash );
                hash.clear();
                formula_idx++;
            }
            else if( formula[formula_idx] == ')' )
            {
                formula_idx++;
                int occurence = 1;
                int tmp_idx = formula_idx;
                if( isdigit( formula[tmp_idx] ) )
                {
                    occurence = 0;
                    while( tmp_idx < formula.size() && isdigit( formula[tmp_idx] ) )
                        occurence = occurence*10+(formula[tmp_idx++]-'0');
                }
                formula_idx = tmp_idx;
                
                for( auto it=hash.begin(); it!=hash.end(); it++ )
                    it->second *= occurence;
                
                unordered_map<string,int> next_hash = stack.top();
                stack.pop();
                for( auto it=hash.begin(); it!=hash.end(); it++ )
                {
                    auto it2 = next_hash.find(it->first);
                    if( it2 == next_hash.end() )
                        next_hash[it->first] = it->second;
                    else
                        next_hash[it->first] += it->second;
                }
                hash = next_hash;
            }
            else if( isalpha(formula[formula_idx]) )
            {
                string element(1, formula[formula_idx++]);
                int occurence = 1;
                int tmp_idx = formula_idx;
                while( tmp_idx < formula.size() && isalpha( formula[tmp_idx] ) && islower(formula[tmp_idx]) )
                {
                    element += formula[tmp_idx++];
                }
                if( tmp_idx < formula.size() && isdigit( formula[tmp_idx] ) )
                {
                    occurence = 0;
                    while( tmp_idx < formula.size() && isdigit( formula[tmp_idx] ) )
                        occurence = occurence*10+(formula[tmp_idx++]-'0');
                }
                hash[element] += occurence;
                formula_idx = tmp_idx;
            }
        }
        std::vector<string> str_ans;
        for( auto it = hash.begin(); it != hash.end(); it++ )
            str_ans.insert(str_ans.begin(), it->first);
        
        sort(str_ans.begin(), str_ans.end(), less<string>());
        for( auto s : str_ans )
            ans = ans + s + ((hash[s]==1) ? "" : to_string(hash[s]));
        
        return ans;
    }
};
