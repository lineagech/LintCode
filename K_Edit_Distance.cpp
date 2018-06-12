class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
     
    class TrieNode
    {
    public:
        static void insert(string& w, TrieNode* root)
        {
            TrieNode* curr = root;
            for(int i = 0; i<w.size(); i++)
            {
                if((curr->children[w[i]-'a']) == NULL)
                {
                    (curr->children[w[i]-'a']) = new TrieNode(); 
                }
                curr = (curr->children[w[i]-'a']);
            }
            curr->is_word = true;
            curr->word = w;
        }
        TrieNode(){
            is_word = false;
            word = "";
            children.resize(26,NULL);
        }
        vector<TrieNode*> children;
        bool is_word;
        string word;
    };
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        TrieNode root;
        for(auto word : words)
        {
            TrieNode::insert(word, &root);
        }
        vector<string> ans;
        vector<int> dp(target.size()+1, INT_MAX);
        for(int i=0; i<target.size()+1; i++) 
            dp[i] = i;
        find(&root, target, k, ans, dp);
        return ans;
    }
    
    void find(TrieNode* curr, string& target, int k, vector<string>& ans, vector<int>& dp)
    {
        count++;
        if( curr->is_word )
        {
            if(dp[target.size()] <= k) ans.push_back(curr->word);
        }
        for(int i=0; i<26; i++)
        {
            if(curr->children[i] != NULL) // there are some words
            {
                vector<int> next_dp(target.size()+1, INT_MAX);
                next_dp[0] = count;
                for(int j=1; j<=target.size(); j++)
                {
                    if( i == target[j-1]-'a' )
                        next_dp[j] = dp[j-1];
                    else
                        next_dp[j] = dp[j-1]+1;
                    next_dp[j] = min( next_dp[j], min(next_dp[j-1],dp[j])+1 );
                }
                find(curr->children[i], target, k, ans, next_dp);
            }
        }
        count--;
    }
    int count;
    
};
