class Solution {
public:
    /*
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        double left = (double)(*(std::min_element(nums.begin(), nums.end())));
        double right = (double)(*(std::max_element(nums.begin(), nums.end())));
        
        while( right-left > 1e-5 )
        {
            double mid = (left+right)/2;
            double minSum = 0;
            bool needLarger = false;
            vector<double> sum(n+1, 0.0);
            for( int i=1; i<=n; i++ )
            {
                sum[i] = sum[i-1] + (nums[i-1]-mid);
                if( i >= k ) minSum = min(minSum, sum[i-k]);
                if( i>=k && sum[i]>minSum )
                {
                    needLarger = true;
                    break;
                }
            }
            if( needLarger ) left = mid;
            else right = mid;
        }
        return right;
    }
};
