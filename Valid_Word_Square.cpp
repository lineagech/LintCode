class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        // Write your code here
    	int len = words.size();
    	if( len == 0 ) return false;
    	int word_size = words[0].size();
    	if( len != word_size ) return false;

    	for( int i = 0; i < len; i++ )
    	{
    		string check_str = words[i].substr(0, i+1);
    		if( words[i].size() != word_size ) return false;
    		for( int j = 0; j < (i+1); j++ )
    		{
    			if( check_str[j] != words[j][i] ) return false;
    		}
    	}
    	return true;
    }
};
