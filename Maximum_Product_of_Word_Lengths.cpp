class Solution {
public:
    /**
     * @param words: a string array
     * @return: the maximum product
     */
    int maxProduct(vector<string> &words) {
        // Write your code here
        int n = words.size();
        int ans = 0;
        vector<int> mask(n,0);
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < words[i].size(); j++ )
                mask[i] |= (1<<(words[i][j]-'a'));
            for( int j = i-1; j >= 0; j-- )
            {
                if( (mask[i] & mask[j]) == 0x0 )
                {
                    ans = max( (int)words[i].size()*(int)words[j].size(), ans );
                }
            }
        }
        return ans;
    }
};
