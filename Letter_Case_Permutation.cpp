class Solution {
public:
    /**
     * @param S: a string
     * @return: return a list of strings
     */
    vector<string> letterCasePermutation(string &S) {
        // write your code here
        vector<string> ans;
        ans.push_back(S);
        helper(S, ans, 0);
        return ans;
    }
    void helper(string &S, vector<string>& ans, int start)
    {
        for( int i = start; i < S.size(); i++ )
        {
            if( isalpha(S[i]) ) {
                string new_S(S);
                string repl_str = "";
                if( isupper(S[i]) ) repl_str += (char)tolower(S[i]);
                else repl_str += (char)toupper(S[i]);
                new_S.replace(i, 1, repl_str);
                ans.push_back(new_S);
                helper(new_S, ans, i+1);
            }
        }
    }
};
