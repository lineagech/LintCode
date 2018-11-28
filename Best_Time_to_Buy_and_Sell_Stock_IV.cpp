class Solution {
public:
    /**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
    int maxProfit(int K, vector<int> &prices) {
        int n = prices.size();
        vector<int> local(n+1, 0);
        vector<int> global(n+1, 0);
        int increase;
        if (K >= prices.size() / 2)
        {   
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i-1] > 0) {
                    ans += prices[i] - prices[i-1];
                }
            }
            return ans;
        }
        for( int k=1; k<=K; k++ ) 
        {   
            int tmp = global[0];
            for( int i=1; i<n; i++ )
            {
                increase = (prices[i]-prices[i-1]);
                local[i] = max( tmp+increase, 
                            local[i-1]+increase);
                tmp = global[i];
                global[i] = max( global[i-1], local[i] );
            }
        }
        return global[n-1];
    }
};
