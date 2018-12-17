class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        unordered_map<int,int> next, curr;
        next[0] = 0;
        for( int i = 0; i < n; i++ )
        {
            curr = next;
            for( auto dp : curr )
            {
                int diff = dp.first;
                next[diff+rods[i]] = max( next[diff+rods[i]],
                                          curr[diff] );
                next[abs(diff-rods[i])] = max( next[abs(diff-rods[i])], 
                                               curr[diff]+min(diff,rods[i]) );
            }
        }
        return next[0];
    }
};
