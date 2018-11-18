class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if( x < 0 ) return -1;
        if( x == 0 ) return 0;
        if( x == 1 ) return 1;
        int start = 0;
        int end = x;
        while( start < end )
        {
            long long mid = (start+end)/2;
            if( mid*mid > (long long)x ) end = mid;
            else if( mid*mid == (long long)x ) return mid;
            else start = mid+1;
        }
        return start-1;
    }
};
