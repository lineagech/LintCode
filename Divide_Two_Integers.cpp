class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        if( divisor == 0 ) return 1;
        bool neg = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
        long long dividend_l = (dividend < 0) ? -1*(long long)dividend : dividend;
        long long divisor_l = (divisor < 0) ? -1*(long long)divisor : divisor;
        long long start = 1;
        long long end = dividend_l+1;
        while( start < end )
        {
            long long mid = (start+end)/2;
            if( (long long)divisor_l*mid > dividend_l ) {
                end = mid;
            }
            else if( (long long)divisor_l*mid < dividend_l ) {
                start = mid+1;
            }
            else {
                if( !neg && mid > 2147483647 || neg && mid > 2147483648  ) 
                    return 2147483647;
                return (neg) ? -1*mid : mid;
            }
        }
        if( !neg && (start-1) > 2147483647 || neg && (start-1) > 2147483648 ) 
            return 2147483647;
        return (neg) ? -1*(start-1) : start-1;
    }
};
