class Solution {
public:
    /**
     * @param n: an integer
     * @return: if n is a power of three
     */
    bool isPowerOfThree(int n) {
        // Write your code here
        return (n>0 && int(log10(n)/log10(3))-(log10(n)/log10(3))==0 );
    }
};
