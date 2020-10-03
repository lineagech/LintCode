class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        # dp[i][s|(1<<j)] = min(dp[i][s|(1<<j)],
        #                       dp[i][s] + cost[i][j])
        #                       dp[i-1][s] + cost[i][j])
        
        kInf = 1e9
        m = len(cost)
        n = len(cost[0])
        dp = [[kInf for j in range(1<<n)] for i in range(m+1)]
        
        dp[0][0] = 0
        for i in range(1, m+1):
            for j in range(n):
                for s in range((1<<n)):
                    dp[i][s|(1<<j)] = min(dp[i][s|(1<<j)],\
                                          dp[i][s] + cost[i-1][j],\
                                          dp[i-1][s] + cost[i-1][j])
        
        return dp[m][(1<<n)-1]
