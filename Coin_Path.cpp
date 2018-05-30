vector<int> dp(A.size(), INT_MAX);
        vector<int> path(A.size(), 0);
        vector<int> ans;
        dp[A.size()-1] = A[A.size()-1];
        path[A.size()-1] = A.size();
        for(int i=A.size()-2; i>=0; i--)
        {
            if(A[i]== -1) continue;
            for(int j=1; j<=B; j++)
            {
                if( ((i+j)<A.size()) &&
                    (((long long)A[i]+(long long)dp[i+j])<(long long)dp[i]) )
                {
                    dp[i] = A[i]+dp[i+j];
                    path[i] = i+j;
                }
            }
        }
 
        for(int i=0; i<A.size(); )
        {
            if(path[i] != 0)
            {
                ans.push_back(i+1);
                i = path[i];
            }
            else return vector<int>();
        }
        return ans;
