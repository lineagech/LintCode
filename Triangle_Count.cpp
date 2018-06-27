class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        if( S.size() < 3 ) return 0;
        sort(S.begin(), S.end());
        int ans = 0;
        for(int i=0; i<S.size()-2; i++)
        {
            if(S[i] <= 0) return 0;
            for(int j=i+1; j<S.size()-1; j++)
            {
                int two_sum = (S[i]+S[j]);
                auto ubound = std::upper_bound(S.begin(), S.end(), two_sum);
                if( *(ubound-1) == two_sum ) ubound--;
                ans += ((ubound-(S.begin()+j+1))); 
                //while( S[j+1] == S[j] ) j++;
            }
        }
        return ans;
    }
};
