class Solution {
public:
    /**
     * @param s: the given expression
     * @return: the result of expression
     */
    int calculate(string &s) {
        // Write your code here
        std::stack<pair<int,char>> stack;
        int s_idx = 0;
        int result = 0;
        bool negative = false;
        char op = '+';
        while( s[s_idx] == ' ' ) s_idx++;
        if( s[s_idx] == '-' ) {
            negative = true;
            s_idx++;
        }
        // next should be '+' or '-'
        while( s_idx < s.size() )
        {
            if( isdigit(s[s_idx]) )
            {
                result = 0;
                while( s_idx < s.size() && isdigit(s[s_idx]) )
                {
                    result = result*10+(s[s_idx]-'0');
                    s_idx++;
                }
                if( negative ) { 
                    result *= -1;
                    negative = false;
                }
            }
            else if( s[s_idx] == '(' )
            {
                stack.push( make_pair(result,op) );
                s_idx++;
                while( s_idx < s.size() && s[s_idx] == ' ' ) s_idx++;
                // handle negative 
                negative = false;
                if( s[s_idx] == '-' ){ 
                    negative = true;
                    s_idx++;
                }
                
                // get number 
                result = 0;
                while( s_idx < s.size() && isdigit(s[s_idx]) )
                {
                    result = result*10+(s[s_idx]-'0');
                    s_idx++;
                }
                if( negative ) { 
                    result *= -1;
                    negative = false;
                }
            }
            else if( s[s_idx] == ')' )
            {
                pair<int,char> prev = stack.top();
                stack.pop();
                
                if( prev.second == '-' ) result = prev.first - result;
                else result += prev.first;
                
                //cout << result << "," << prev.first << endl;
                s_idx++;
            }
            else if( s[s_idx] == '+' || s[s_idx] == '-' )
            {
                if( s[s_idx] == '-' ) negative = true;
                else negative = false;
                op = s[s_idx];
                s_idx++;
                while( s_idx < s.size() && s[s_idx] == ' ' ) s_idx++;
                
                if( s[s_idx] == '(' ) 
                    continue;
 
                int next_element = 0;
                while( s_idx < s.size() && isdigit(s[s_idx]) )
                {
                    next_element = next_element*10+(s[s_idx]-'0');
                    s_idx++;
                }
                result += (negative) ? -next_element : next_element;

            }
            else s_idx++;
        }
        return result;
    }
};
