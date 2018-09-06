class Solution {
public:
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    string addBoldTag(string &s, vector<string> &dict) {
        // write your code here
        int s_len = s.size();
        int prev_bound = 0;
        vector<bool> in_dict(s_len, false);
        /* to check where are valid ranges in s */
        for( int i=0; i<s_len; i++ )
        {   
            for( auto str : dict )
            {
                string tmp = s.substr(i, str.size());
                if( tmp == str )
                    prev_bound = max( prev_bound, (int)(i+str.size()));
            }
            in_dict[i] = (i < prev_bound); 
        }
        
        string result = "";
        for( int i=0; i<s_len; )
        {
            if( !in_dict[i] ) { 
                result.push_back(s[i++]);
                continue;
            }
            else{
                int start = i;
                while( i < s_len && in_dict[i] ) i++;
                result += "<b>" + s.substr(start, i-start) + "</b>";
            }
        }
        return result;
    }
};
