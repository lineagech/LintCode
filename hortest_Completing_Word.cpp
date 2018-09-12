class Solution {
public:
    /**
     * @param licensePlate: a string
     * @param words: List[str]
     * @return: return a string
     */
    string shortestCompletingWord(string &licensePlate, vector<string> &words) {
        // write your code here
        unordered_map<char,int> hash;
        for( auto c : licensePlate ) {
            char lower_c = tolower(c);
            if( lower_c>='a' && lower_c<='z' ) {
                hash[lower_c] += 1;
            }
        }
        sort( words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        } );
        for( auto word : words )
        {   
            unordered_map<char,int> word_hash;
            bool valid = true;
            for( auto c : word ) {
                char lower_c = tolower(c);
                if( lower_c>='a' && lower_c<='z' )
                    word_hash[lower_c] += 1;
            }
            for( auto it : hash )
            {
                if( word_hash[it.first] < it.second ) {
                    valid = false;
                    break;
                }
            }
            if( valid ) return word;
        }
        return "";
    }
};
