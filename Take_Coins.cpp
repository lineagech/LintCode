class Solution {
public:
    /**
     * @param list: The coins
     * @param k: The k
     * @return: The answer
     */
    int takeCoins(vector<int> &list, int k) {
        // Write your code here
        int n = list.size();
        vector<int> sum(n+1, 0);
        if( list.size() == 0 ) return 0;
        if( k > n ) {
            int total = accumulate(list.begin(), list.end(), 0);
            return total;
        }
        for( int i = 1; i <= list.size(); i++ )
        {
            sum[i] = sum[i-1]+list[i-1];
        }
        int max_value = 0;
        for( int i=0; i+(n-k)<=n; i++ )
        {
            int j = i+(n-k-1);
            int tmp_value = 0;
            tmp_value += get_range_sum(0, i-1, sum);
            tmp_value += get_range_sum(j+1, n-1, sum);
            max_value = max(max_value, tmp_value);
        }
        return max_value;
    }
    int get_range_sum(int start, int end, vector<int>& sum)
    {
        if( end < 0 ) return 0;
        if( start >= sum.size()-1 ) return 0;
        return (sum[end+1]-sum[start]);
    }
};
