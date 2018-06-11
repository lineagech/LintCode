class WordDictionary {
public:
    class TrieNode {
    public:
        TrieNode()
        {
            is_string = false;
            children.resize(26, NULL);
        }
        vector<TrieNode*> children;
        bool is_string;
    };
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        // write your code here
        TrieNode* curr = &root;
        for(int i=0; i<word.size(); i++)
        {
            if( curr->children[word[i]-'a'] == NULL )
            {
                curr->children[word[i]-'a'] = new TrieNode();
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->is_string = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs_search(word, 0, &root);
    }
    bool dfs_search(string &word, int pos, TrieNode* curr)
    {
        if(curr == NULL) return false;
        if(pos == word.size()) return curr->is_string;
        
        if(word[pos] == '.')
        {
            for( int i = 0; i < 26; i++ )
            {
                if( dfs_search(word, pos+1, curr->children[i]) )
                {
                    return true;
                }
            }
        }
        else
        {
            if( dfs_search(word, pos+1, curr->children[word[pos]-'a']) )
            {
                return true;
            }
        }
        return false;
    }
    
    TrieNode root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
