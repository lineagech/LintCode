class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        stack<int> num_stack;
        stack<string> str_stack;
        string curr = "";
        for( int i = 0; i < s.size(); i++ )
        {   
            if( isdigit(s[i]) ) { //push stack
                int num_rep = 0;
                while( i<s.size() && isdigit(s[i]) ) 
                    num_rep = num_rep*10+(s[i++]-'0');
                if( i<s.size() && s[i]=='[' )
                {
                    num_stack.push(num_rep);
                    str_stack.push(curr);
                    curr = "";
                }
                else {
                    curr += to_string(num_rep);
                    i--;
                }
            }
            else if( s[i] == ']' ) { // pop stack
                int num_rep = num_stack.top(); num_stack.pop();
                string prev = str_stack.top(); str_stack.pop();
                string base = curr;
                for( int j = 0; j < num_rep-1; j++ )
                    curr += base;
                if(num_rep > 0) curr = prev+curr;
                else curr = prev;
            }
            else { // append characters
                curr += s[i];
            }
        }
        return curr;
    }
};
