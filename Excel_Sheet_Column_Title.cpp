class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a string
     */
    string convertToTitle(int n) {
        // write your code here
        if( n <= 0 ) return "";
        if( n == 1 )  return "A";
        int base = 26;
        int new_n = n-1;
        string ans = "";
        while( new_n > 0 )
        {
            int res = new_n % base;
            char char_res = ('A'+res);
            ans = char_res + ans;
            new_n /= 26;
            new_n -= 1;
            if( new_n == 0 && n >= 27 ) {
                ans = 'A' + ans;
                break;
            }
        }
        return ans;
    }
};
