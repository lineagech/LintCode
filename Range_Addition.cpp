class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here
        vector<int> result(length+1, 0);
        if( length == 0 ) return vector<int>();
        for( update : updates )
        {
            result[update[0]] += update[2];
            result[update[1]+1] -= update[2];
        }
        int init = result[0];
        for( int i = 1; i < length; i++ )
        {
            result[i] += init;
            init = result[i];
        }
        vector<int> ans(result.begin(), result.end()-1);
        return ans;
    }
    
    
};
