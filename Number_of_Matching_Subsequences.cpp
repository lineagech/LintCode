class Solution {
public:
    int numMatchingSubseq(string &S, vector<string> &words) {
        // Write your code here
        int ans = 0;
        unordered_set<string> hash, not_hash;
        for( auto word : words ) {
            if( hash.find(word) != hash.end() ) {
                ans++;
                continue;
            }
            if( not_hash.find(word) != not_hash.end() ) continue;
            if( isSubSeq(S, word) ) {
                ans++;
                hash.insert(word);
            }
            else
            {
                not_hash.insert(word);
            }
        }
        return ans;
    }
    bool isSubSeq( string& S, string word )
    {
        int S_idx = 0, word_idx = 0;
        int S_size = S.size(), word_size = word.size();
        while( S_idx < S_size && word_idx < word_size  )
        {
            if( S[S_idx++] == word[word_idx] )
                word_idx++;
        }
        return (word_idx == word_size);
    }
};
