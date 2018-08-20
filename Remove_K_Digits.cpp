class Solution {
public:
    /**
     * @param num: a string
     * @param k: an integer
     * @return: return a string
     */
    string removeKdigits(string &num, int k) {
        // write your code here
        stack<char> stack;
        int len = num.size()-k;
        
        if( len <= 0 || k < 0 ) return "0";
        stack.push(num[0]);
        for( int i=1; i<num.size(); i++ )
        {
            while( stack.size()>0 && stack.top()>num[i] && 
                   (stack.size()+(num.size()-1-i)>=len) )
            {
                stack.pop();
            }
            if( stack.size()>0 && stack.top() == num[i] && stack.size() == len ) continue;
            stack.push(num[i]);
        }
        string ans = "";
        while( !stack.empty() )
        {
            ans += stack.top();
            stack.pop();
        }   
        reverse(ans.begin(), ans.end());
        while( ans[0] == '0' ) ans.erase(0,1);
        return (ans=="") ? "0" : ans;
    }
};
