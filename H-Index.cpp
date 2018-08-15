class Solution {
public:
    /**
     * @param citations: a list of integers
     * @return: return a integer
     */
    int hIndex(vector<int> &citations) {
        // write your code here
        if( citations.size() == 0 ) return 0;
        int high = *max_element(citations.begin(), citations.end());
        int low = 0;
        while( low < high )
        {
            int mid = (low+high)/2;
            if( check_valid(citations, mid) )
                low = mid+1;
            else
                high = mid;
        }
        return (check_valid(citations,low) ? low : low-1);
    }
    bool check_valid(vector<int>& citations, int h_idx)
    {
        int count1 = 0;
        int count2 = 0;
        for( auto c : citations )
        {
            if( c >= h_idx ) count1++;
            if( c < h_idx ) count2++;
        }
        return ( count1>=h_idx && (count2<=(citations.size()-h_idx)) );
    }
};
