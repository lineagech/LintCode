class Solution {
public:
    /**
     * @param temperatures: a list of daily temperatures
     * @return: a list of how many days you would have to wait until a warmer temperature
     */
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        // Write your code here
        int n = temperatures.size();
        vector<int> ans(n,0);
        if( n == 0 ) return ans;
        
        /* Use stack to find the first temperature which is larger */
        stack<pair<int,int>> stack;
        stack.push( make_pair(0,temperatures[0]) );
        for( int i=1; i<n; i++ )
        {
            while( !stack.empty() && temperatures[i] > stack.top().second )
            {
                // pop and put into the answer
                auto temp = stack.top();
                stack.pop();
                ans[temp.first] = (i-temp.first);
            }
            stack.push( make_pair(i,temperatures[i]) );
        }
            
        return ans;
    }
};
