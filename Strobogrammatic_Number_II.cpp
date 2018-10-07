class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    string pattern[5] = {"1","6","8","9","0"};
    vector<string> findStrobogrammatic(int n) {
        vector<string> q;
        if( n == 0 ) return {""};
        if( n % 2 == 0 ) {
            if( n != 2 ) q.push_back("00");
            q.push_back("11");
            q.push_back("69");
            q.push_back("88");
            q.push_back("96");
        } else {
            q.push_back("0");
            q.push_back("1");
            q.push_back("8");
        }
        for( int i = 4-n%2; i <= n; i+=2 )
        {   
            vector<string> tmp;
            for( auto p : q ) {
                if( i != n ) tmp.push_back(pattern[4]+p+pattern[4]);
                tmp.push_back(pattern[0]+p+pattern[0]);
                tmp.push_back(pattern[1]+p+pattern[3]);
                tmp.push_back(pattern[2]+p+pattern[2]);
                tmp.push_back(pattern[3]+p+pattern[1]);
            }
            q = tmp;
        }
        return q;
    }
};
