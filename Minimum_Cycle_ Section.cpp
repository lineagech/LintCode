class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) {
        // Write your code here
        // use KMP-Algorithm...
        if( array.size() == 0 ) return 1;
        vector<int> index(array.size(), -1);
        for( int i=1; i<array.size(); i++ )
        {
            int tmp_idx = index[i-1];
            while( tmp_idx >= 0 && array[tmp_idx+1]!=array[i] )
                tmp_idx = index[tmp_idx];
            if( array[tmp_idx+1] == array[i] ) 
                index[i] = tmp_idx+1;
        }
        
        // Check 
        return ( array.size() - (index[array.size()-1]+1) );
    }
};
