class Solution {
public:
    /**
     * @param words1: a list of string
     * @param words2: a list of string
     * @param pairs: a list of string pairs
     * @return: return a boolean, denote whether two sentences are similar or not
     */
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        // write your code here
        unordered_map<string,unordered_set<string>> hash;
        for(auto pair : pairs) {
            hash[pair[0]].insert(pair[1]);
            hash[pair[1]].insert(pair[0]);
        }
        for( int i = 0; i < words1.size(); i++ )
        {
            if( !hash.count(words1[i]) || !hash[words1[i]].count(words2[i]) )
            {
                if( words1[i] == words2[i] ) continue;
                return false;
            }
        }
        return true;
    }
};
