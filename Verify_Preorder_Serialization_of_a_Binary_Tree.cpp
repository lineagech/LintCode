class Solution {
public:
    /**
     * @param preorder: a string
     * @return: return a bool
     */
    bool isValidSerialization(string &preorder) {
        // write your code here
        stack<string> stack;
        int n = preorder.size();
        if( n == 0 ) return false;
        if( n == 1 && preorder=="#" ) return true;
        
        unordered_map<string,int> hash;
        bool entered = false;
        int layer = 0;
        string curr;
        stringstream ss(preorder); //cout << preorder << endl;
        while( getline(ss, curr, ',') )
        {   
            //cout << curr << endl;
            if( entered && stack.empty() ) {
                return false;
            }
            if( !stack.empty() ) hash[stack.top()] += 1;
            if( curr != "#" )
            {   
                if( !entered ) entered = true;
                stack.push(curr+to_string(layer));
                layer++;
            }
            while( !stack.empty() && hash[stack.top()] == 2 ) {
                stack.pop();
            }
        }
    
        if( !entered ) return false;
        
        for( auto it : hash ) {
            if( it.second != 2 ) { 
                return false;
            }
        }
        return true;
    }
};
