class Solution {
public:
    /**
     * @param A: the given number
     * @param B: another number
     * @return: the last digit of B! / A! 
     */
    int computeLastDigit(long long A, long long B) {
        // write your code here
        int lastDigit = 1;
        int start = (A+1)%10;
        int end = B%10;
        
        if( A == B ) return 1;
        if( B > A+10 || start > end ) return 0;
        for( int k = start; k <= end; k++ )
        {
            lastDigit *= (k%10);
            lastDigit %= 10;
        }
        return (int)lastDigit;
    }
};
