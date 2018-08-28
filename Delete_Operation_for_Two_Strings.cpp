class Solution {
public:
    /**
     * @param word1: a string
     * @param word2: a string
     * @return: return a integer
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int word1_len = word1.size();
        int word2_len = word2.size();
        vector<vector<int>> dp(word1_len+1, vector<int>(word2_len+1, 0));
        for( int i=0; i<=word1_len; i++ ) dp[i][0] = i;
        for( int j=0; j<=word2_len; j++ ) dp[0][j] = j;
        
        for( int i=1; i<=word1_len; i++)
        {
            for( int j=1; j<=word2_len; j++ )
            {
                dp[i][j] = (word1[i-1]==word2[j-1]) ? (dp[i-1][j-1]) : 
                ( min(dp[i-1][j], dp[i][j-1])+1 );
            }
        }
        return dp[word1_len][word2_len];
    }
};
