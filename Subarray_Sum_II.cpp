class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        int n = A.size();
        int ans = 0;
        vector<int> sum(n+1, 0);
        for( int i=1; i<=n; i++ ) sum[i]=sum[i-1]+A[i-1];
        for( int i=1; i<=n; i++ )
        {
            auto up = upper_bound(sum.begin(), sum.begin()+i, sum[i]-start);
            auto down = lower_bound(sum.begin(), sum.begin()+i, sum[i]-end);
            ans += (up-down);
        }
        return ans;
    }
};
