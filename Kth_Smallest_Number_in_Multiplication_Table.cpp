class Solution {
public:
    /**
     * @param m: a integer
     * @param n: a integer
     * @param k: a integer
     * @return: return a integer
     */
    class MyComp
    {
    public:
        bool operator()(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b)
        {
            return a.first > b.first;
        }
    };
    int findKthNumber(int m, int n, int k) {
        // write your code here
        int low = 1;
        int high = m*n;
        int count = 0;
        std::vector<int> n_array(n);
        if( m==0 || n==0 || k==0 ) return 0;
        if( m*n < k ) return 0;
        if( m*n == k ) return m*n;
        
        for( int i=1; i<=n; i++) 
            n_array[i-1] = i; 
            
        while( low < high )
        {
            int mid = (low+high)/2; 
            count = 0;
            for( int i=1; i<=m; i++)
            {
                auto it = lower_bound(n_array.begin(), n_array.end(), (mid+i-1)/i);
                count += (it - n_array.begin());
            }
            if( count >= k ) high = mid;
            else if( count < k ) low = mid+1;
        }
       
        return low-1;
    }
};
