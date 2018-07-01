class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    class MyComp{
    public:
        bool operator()(pair<int,int>& a, pair<int,int>& b)
        {
            return !((a.first>b.first) 
                || (a.first==b.first && a.second<b.second) );
        }
    };
     
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // write your code here
        vector<int> dp(envelopes.size(), 1), 
                    heights(envelopes.size(), INT_MAX);
        int ans = 0;
        sort(envelopes.begin(), envelopes.end(), MyComp());
        if( envelopes.size() == 0 ) return 0;
        
        heights[0] = envelopes[0].second;
        for( int i=1; i<envelopes.size(); i++ )
        {
            int h_idx = lower_bound(heights.begin(), heights.end(), envelopes[i].second) - heights.begin();
            dp[i] = h_idx+1;
            heights[h_idx] = envelopes[i].second;
        }
        for( int i=0; i<envelopes.size(); i++ )
            ans = max(dp[i], ans);
        
        return ans;
    }
};
