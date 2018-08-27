class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        // write your code  here
        sort( d.begin(), d.end(), [](string& a, string& b){ 
                
                return (a.size() > b.size()) || (a.size() == b.size() && a.compare(b)<=0 ); 
            
        });

        int s_size = s.size();
        
        for( auto w : d )
        {
            if( w.size() <= s_size )
            {
                if( isSubSeq(s, w) ) return w;
            }
        }
        return "";
    }
    bool isSubSeq( string& w1, string w2 )
    {
        int idx1 = 0, w1_len = w1.size();
        int idx2 = 0, w2_len = w2.size();
        while( idx1 < w1_len && idx2 < w2_len )
        {
            while( w1[idx1] != w2[idx2] ){
                idx1++;
                if( idx1 >= w1_len ) return false;
            }
            idx1++; idx2++;
        }
        return (idx2 == w2_len);
    }
};
