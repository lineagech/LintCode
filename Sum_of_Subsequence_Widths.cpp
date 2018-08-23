class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        long long mod = 1e9+7;
        int n = A.size();
        long long ans = 0;
        sort(A.begin(), A.end());
        
        long long pow2[n] = {0};
        pow2[0] = 1;
        for( int i=1; i<n; i++ ) pow2[i] = (pow2[i-1]*2) % mod;
        
        for( int i=0; i<n; i++ )
        {
            ans = ( ans + (long long)A[i]*(pow2[i] - pow2[n-i-1]) ) % mod;
        }
        return ans;
    }
};
