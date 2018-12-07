class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the maximun difference
     */
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        if( max_val == min_val ) return 0;
        double avg_gap = (double)(max_val-min_val)/(double)(n-1);
        vector<pair<int,int>> bucket(n);
        for( int i=0; i<n; i++ ) {
            bucket[i] = make_pair(INT_MAX, INT_MIN);
        }
        for( int i=0; i<n; i++ )
        {
            int idx = (double)(nums[i]-min_val)/avg_gap;
            bucket[idx].first = min(bucket[idx].first, nums[i]);
            bucket[idx].second = max(bucket[idx].second, nums[i]);
        }
        int ans = INT_MIN;
        int prev_max = min_val;
        for( int i=0; i<n; i++ )
        {   
            if( bucket[i].first == INT_MAX && bucket[i].second == INT_MIN ) continue;
            ans = max(ans, bucket[i].first-prev_max);
            ans = max(ans, bucket[i].second-bucket[i].first);
            prev_max = bucket[i].second;
        }
        return ans;
    }
};
