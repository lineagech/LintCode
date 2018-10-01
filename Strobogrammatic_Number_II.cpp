class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    int step = 0;
    vector<string> findStrobogrammatic(int n) {
        // write your code here
        // 0<->0
        // 1<->1 
        // 6<->9
        // 8<->8 
        // 9<->6
        char pattern[5] = {'1', '6', '8', '9', '0'};
        vector<string> ans;
        if( n == 0 ) {
            ans.push_back("");
        }
        if( n == 1 ) {
            ans.push_back("0");
            ans.push_back("1");
            ans.push_back("8");
        }
        else if( n == 2 )
        {
            ans.push_back("11");
            ans.push_back("69");
            ans.push_back("88");
            ans.push_back("96");
        }
        else if( n > 2 ){
            step++;
            vector<string> tmp = findStrobogrammatic(n-2);
            step--;
            if( n-2 == 2 ) tmp.insert(tmp.begin(), "00");
            for( auto p : tmp )
            {   
                string next;
                for( int i=0; i<4; i++ )
                {
                    next = p;
                    next.insert(next.begin(), 1, pattern[i]);
                    next.insert(next.end(), 1, pattern[(4-i)%4]);
                    ans.push_back(next);
                }
                if( step != 0 )
                {
                    next = p;
                    next.insert(next.begin(), 1, pattern[4]);
                    next.insert(next.end(), 1, pattern[4]);
                    ans.push_back(next);
                }
            }
        }
        return ans;
    }
};
