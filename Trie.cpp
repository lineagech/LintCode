class Trie {
public:
    
    class TrieNode
    {
    public:
        TrieNode()
        {
            is_string = false;   
        }
        bool is_string;
        map<char,TrieNode*> children;
    };

    Trie() {
        // do intialization if necessary
        root = new TrieNode();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++)
        {   
            auto it = curr->children.find(word[i]);
            if( it == curr->children.end() ) // not found
            {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
        }
        curr->is_string = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            auto it = curr->children.find(word[i]);
            if(it == curr->children.end())
            {
                return false;
            }
            curr = it->second; 
        }
        return (curr->is_string);
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        TrieNode* curr = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            auto it = curr->children.find(prefix[i]);
            if( it == curr->children.end() )
            {
                return false;
            }
            curr = it->second;
        }
        return true;
    }
    
    TrieNode* root;
};
