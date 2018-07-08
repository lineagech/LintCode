class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        // 0, s[0], s[1], ......
        // 0, p[0], p[1], ......
        // dp[i][j] = ( p[j]=='*' ) ? ( dp[i][j-1] || dp[i-1][j] ) : dp[i-1][j-1]
        if( p.size() == 0 )
        {
            if( s.size() == 0 ) return true;
            else return false;
        }
        if( s.size() == 0 )
        {
            if( p[0] != '*' ){
                return false;
            }
        }
        
        vector<vector<bool>> dp( s.size()+1, vector<bool>(p.size()+1, false) );
        dp[0][0] = true;
        if( p[0] == '*' ) {
            dp[0][1] = true;
            for( int j=2; j<=p.size(); j++ ) dp[0][j] = (p[j-1]=='*' && dp[0][j-1]);
        }
        for( int i=1; i<=s.size(); i++ )
        {
            for( int j=1; j<=p.size(); j++ )
            {
                if( s[i-1]==p[j-1] || p[j-1]=='?' || p[j-1]=='*' )
                {
                    dp[i][j] = ( p[j-1]=='*' ) ? ( dp[i][j-1] || dp[i-1][j] ) 
                                             : ( dp[i-1][j-1] );
                }
            }
        }
        return dp[s.size()][p.size()];
        /* Recursive Solution
        if( p.size() == 0 )
        {
            if( s.size() == 0 ) return true;
            else return false;
        }
        if( s.size() == 0 )
        {
            if( p[0] == '*' ){
                string new_p = p.substr(1);
                return isMatch( s, new_p );
            }
            else return false;
        }
        
        if( s[0]==p[0] || p[0]=='?' || p[0]=='*' )
        {
            string new_s = s.substr(1);
            string new_p = p.substr(1);
            if( p[0] == '*' )
            {
                return ( isMatch(s, new_p) || isMatch(new_s, p) );
            }
            else
            {   
                return isMatch( new_s, new_p );
            }
        }
        return false;
        */
    }
};
