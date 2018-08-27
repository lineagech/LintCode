class Solution {
public:
    /**
     * @param strs: List[str]
     * @return: return an integer
     */
    int findLUSlength(vector<string> &strs) {
        // write your code here
        unordered_map<string,int> hash;
        for( auto str : strs ) hash[str] += 1;
        sort( strs.begin(), strs.end(), 
              [](string& a, string& b){return a.size()>b.size();} );
        //for( auto str : strs ) cout << str << endl;
        for( int i=0; i<strs.size(); i++ )
        {
            if( hash[strs[i]] == 1 )
            {   
                bool result = true;
                for( int j=0; j<i; j++) {
                    if( !(result &= !isSubSeq(strs[j], strs[i])) ) break;
                }
                if( result ) return strs[i].size();
            }
        }
        return -1;
    }
    bool isSubSeq( string word1, string word2 )
    {   
        int idx1 = 0, word1_len = word1.size();
        int idx2 = 0, word2_len = word2.size();
        while( idx1 < word1_len && idx2 < word2_len )
        {
            while( word1[idx1] != word2[idx2] ) { 
                idx1++;
                if( idx1 >= word1_len ) return false;
            }
            idx1++; idx2++;
        }
        return (idx2==word2_len);
    }
};
