class Solution {
public:
    int integerReplacement(int n) {
        // Write your code here
        long long n2 = n;
        int count = 0;
        while( n2 != 1)
        {
            if(n2 & 0x1)
            {
                if( ((n2>>1)&0x1 == 1) && (n2-1!=2))
                    n2 += 1;
                else
                    n2 -= 1;
            }
            else
            {
                n2 >>= 1;
            }
            count++;
        }
        return count;
    }
};
