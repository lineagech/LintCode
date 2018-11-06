class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the palindromic permutations (without duplicates) of it
     */
    vector<string> generatePalindromes(string &s) {
        // write your code here
        int odd_count = 0;
        vector<string> ans;
        unordered_map<char,int> hash;
        target_len = s.size();
        if(s.size() % 2 == 0) odd_len = false;
        else odd_len = true;
        for(auto c : s) hash[c] += 1;
        for(auto it : hash) if( it.second%2 == 1 ) odd_count++;

        if( odd_count > 1) return ans;    
        string res(s);
        helper(res, hash, ans, 0);
        return ans;
    }
    void helper(string& res, unordered_map<char,int>& hash, vector<string>& ans, int pos)
    {
        if( (pos==target_len/2) ) {
            if( odd_len ) {
                for( auto it : hash ) {
                    if(it.second == 1) {
                        res.replace(pos, 1, 1, it.first);
                        break;
                    }
                }
            }
            ans.push_back(res);
            return;
        }
        for( auto& it : hash )
        {
            if( it.second > 1 )
            {   
                res.replace(pos, 1, 1, it.first);
                res.replace(target_len-pos-1, 1, 1, it.first);
                it.second -= 2;
                helper(res, hash, ans, pos+1);
                it.second += 2;
            }
        }
    }
    bool odd_len;
    int target_len;
};
