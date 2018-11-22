class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int n = s.size();
        string extend_s;
        vector<int> pal_len(2*n+1);
        for( auto c : s )
        {
            extend_s += "#";
            extend_s += c;
        }
        extend_s += "#";
        
        /* use Manacher algorithm */
        int rightest = 0;
        int mid_point = 0;
        pal_len[0] = 1;
        for( int i = 1; i < 2*n; i++ )
        {
            if( rightest > i ) {
                pal_len[i] = rightest-i+1;
                if( 2*mid_point-i >= 0 ) {
                    pal_len[i] = min(pal_len[i], pal_len[2*mid_point-i]);
                }
            }
            else pal_len[i] = 1;
            
            while( i+pal_len[i] < 2*n+1 && i-pal_len[i] >= 0 && extend_s[i+pal_len[i]] == extend_s[i-pal_len[i]] )
                pal_len[i]++;
            if( i+pal_len[i]-1 > rightest )
            {
                rightest = i+pal_len[i]-1;
                mid_point = i;
            }
            //cout << pal_len[i] << endl;
        }
        int max_len = 0;
        int max_idx;
        for( int i=0; i<pal_len.size(); i++ ) {
            if( max_len < pal_len[i] ) {
                max_len = pal_len[i];
                max_idx = i;
            }
        }
        
        string ans;
        if(extend_s[max_idx] != '#') ans += extend_s[max_idx];
        for( int i=1; i<max_len; i++ )
            if(extend_s[max_idx-i]!='#') 
                ans = extend_s[max_idx-i]+ans+extend_s[max_idx+i];
        
        return ans;
    }
};
