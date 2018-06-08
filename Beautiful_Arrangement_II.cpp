class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        if(n <= 0 || k<=0 ) return ans;
        int diff = k;
        ans[0] = 1;
        for(int i=1; i<=k; i++) // k element, diff from k to 1
        {
            ans[i] = ans[i-1] + diff;
            diff = (diff > 0) ? -diff+1 : -diff-1;
        }
        for(int i=k+1; i<n; i++)
        {
            ans[i] = i+1;
        }
        
        return ans;
    }
};
