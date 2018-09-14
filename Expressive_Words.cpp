class Solution {
public:
    /**
     * @param S: a string
     * @param words: a list of strings
     * @return: return a integer
     */
    int expressiveWords(string &S, vector<string> &words) {
        // write your code here
        int S_len = S.size();
        int ans = 0;
        for( word : words )
        {
            int word_idx = 0, S_idx = 0;
            for( S_idx = 0; S_idx < S_len; S_idx++ )
            {
                if( word[word_idx] == S[S_idx] ) word_idx++;
                else if( S_idx-1 >= 0 && S[S_idx] == S[S_idx-1] && S_idx+1 < S_len && S[S_idx] == S[S_idx+1] ) S_idx++;
                else if( !( S_idx-2>=0 && S[S_idx-2] == S[S_idx] && S[S_idx-1] == S[S_idx] ) ) break;
            }
            if( (word_idx == word.size() && S_idx == S_len) ) ans++;
        }
        return ans;
    }
};
