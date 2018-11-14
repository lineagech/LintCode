class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        if( L.size() == 0 ) return 0;
        int min_len = 0;
        int max_len = (int)(*max_element(L.begin(), L.end()));
        int count;
        if( k <= 0 ) return max_len;
        while( min_len < max_len )
        {
            count = 0;
            int mid = ((long long)min_len+(long long)max_len)/2;
            if( mid == 0 ) return 0;
            for( auto len : L ) {
                count += len/mid;
            }
            if( count < k ) // too long
                max_len = mid;
            else
                min_len = mid+1;
        }
        return min_len-1; 
    }
};
