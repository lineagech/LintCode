class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // write your code here
        vector<string> ans;
        string curr;
        dfs(n, curr, 0, ans);
        return ans;
    }
    void dfs( int n, string curr, int remaining, vector<string>& ans )
    {
        if( n > 0 )
        {
            dfs(n-1, curr+"(", remaining+1, ans);
        }
        if( remaining > 0 )
        {
            dfs(n, curr+")", remaining-1, ans);
        }
        if( n == 0 && remaining == 0 )
            ans.push_back(curr);
    }
    vector<int> ans;
};
