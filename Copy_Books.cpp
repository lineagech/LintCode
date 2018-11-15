class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int minMin = 0;
        int maxMin = accumulate(pages.begin(), pages.end(), 0);
        while( minMin < maxMin )
        {
            int midMin = (minMin+maxMin)/2;
            int count = 0;
            int accu = 0;
            for( int i = 0; i < pages.size(); i++ )
            {   
                if( pages[i] > midMin ) {
                    count = INT_MAX-1;
                    break;
                }
                accu += pages[i];
                if( accu >= midMin ) {
                    count++;
                    if( accu == midMin ) accu = 0;
                    else accu = pages[i];
                }
            }
            if( accu > 0 ) count++;
            if( count > k ) {
                minMin = midMin+1;
            }
            else {
                maxMin = midMin;
            }
        }
        return minMin;
    }
};
