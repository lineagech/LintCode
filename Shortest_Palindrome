class Solution {
public:
    /**
     * @param str: String
     * @return: String
     */
    string convertPalindrome(string &str) {
        // Write your code here
        int n = str.size();
        string rev = str;
        reverse(rev.begin(), rev.end());
        
        string w = str + "#" + rev;
        vector<int> kmp(w.size(), 0); //length
        /* KMP algo */
        for( int i = 1; i < w.size(); i++ ) {
            int len = kmp[i-1];
            while( len > 0 && w[len] != w[i] ) 
                len = kmp[len-1];
            kmp[i] = len + (w[len]==w[i]);
        }
        return rev.substr(0, n - kmp.back()) + str; 
    }
};
