class Solution {
public:
    /**
     * @param sentence: a list of string
     * @param rows: an integer
     * @param cols: an integer
     * @return: return an integer, denote times the given sentence can be fitted on the screen
     */
    int wordsTyping(vector<string> &sentence, int rows, int cols) {
        int curr_row = 0;
        int curr_col = 0;
        int curr_sen_idx = 0;
        int sentence_num = sentence.size();
        int ans = 0;
        while( curr_row < rows ) 
        {   
            if( curr_sen_idx == sentence_num ) {
                ans++;
                curr_sen_idx = 0;
            }
            if( sentence[curr_sen_idx].size()+curr_col >= cols ) 
            {
                if( sentence[curr_sen_idx].size()+curr_col+1 == cols || 
                    sentence[curr_sen_idx].size()+curr_col == cols ) {
                    curr_sen_idx++;
                }
                curr_col = 0;
                curr_row++;
                    
                continue;
            }
            curr_col += (sentence[curr_sen_idx].size()+1);
            curr_sen_idx++;
        }
        if( curr_sen_idx == sentence_num ) {
            ans++;
        }
        return ans;
    }
};
