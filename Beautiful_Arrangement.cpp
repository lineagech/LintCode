class Solution {
public:
    /**
     * @param N: The number of integers
     * @return: The number of beautiful arrangements you can construct
     */
    int countArrangement(int N) {
        // Write your code here
        vector<int> used(N+1, false);
    	int ans = 0;
    	helper(N, 1, used, ans);
    	return ans;
    }
    void helper( int N, int pos, vector<int>& used, int& ans )
    {
    	if( pos == N+1 ) {
    		ans++;
    		return;
    	}
    	for( int i = 1; i <= N; i++ )
    	{
    		if( !used[i] && (pos%i==0 || i%pos==0) )
    		{
    			used[i] = true;
    			helper(N, pos+1, used, ans);
    			used[i] = false;
    		}
    	}
    }
};
