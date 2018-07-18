class Solution {
public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    class Trie
    {
    public:
        Trie(){ 
            is_word=false;
            word_idx = -1;
            children.assign(26, NULL);
        }
        void add_word(string& w, int idx)
        {
            Trie* curr = this;
            for( auto c : w )
            {
                if( curr->children[c-'a'] == NULL )
                    curr->children[c-'a'] = new Trie();
                curr = curr->children[c-'a'];
            }
            curr->is_word = true;
            curr->word_idx = idx;
        }
        bool is_existing( string& word, int &index )
        {
            Trie* curr= this;
            for( auto c : word )
            {
                if( curr->children[c-'a'] == NULL ) return false;
                curr = curr->children[c-'a'];
            }
            if( curr->is_word ) 
            {
                index = curr->word_idx;
                return true;
            }
            return false;
        }
        vector<Trie*> children;
        bool is_word;
        int word_idx;
    };
    
    bool is_palin( string word )
    {
        for( int i = 0; i < word.size()/2; i++ )
        {
            if( word[i] != word[word.size()-1-i] ) return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string> &words) {
        // Write your code here
        vector<vector<int>> ans;
        vector<int> pair(2);
        Trie* trie = new Trie();
        for( int i = 0; i < words.size(); i++ ) 
            trie->add_word(words[i], i);
        
        for( int i = 0; i < words.size(); i++ )
        {   
            int word_idx = -1;
            for( int j = 0; j < words[i].size(); j++ )
            {   
                string word = words[i].substr(0,j);
                string rev_word( word.rbegin(), word.rend() );
                if( trie->is_existing(rev_word, word_idx) && is_palin(words[i].substr(j)) )
                {   
                    if( word_idx == i ) continue;
                    pair[0] = i;
                    pair[1] = word_idx;
                    ans.push_back( pair );
                }
                
                int prev_idx = word_idx;
                word = words[i].substr(words[i].size()-j);
                rev_word.assign( word.rbegin(), word.rend() );
                if( trie->is_existing(rev_word, word_idx) && is_palin(words[i].substr(0,words[i].size()-j)) )
                {   
                    if( word_idx == i ) continue;
                    //if( prev_idx == word_idx ) continue;
                    pair[0] = word_idx;
                    pair[1] = i;
                    ans.push_back( pair );
                }
            }
            string rev_word( words[i].rbegin(), words[i].rend() );
            if( trie->is_existing(rev_word, word_idx)  )
            {   
                if( word_idx == i ) continue;
                pair[0] = i;
                pair[1] = word_idx;
                ans.push_back( pair );
            }
        }
        return ans;
    }
};
