class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        # dp[target][house][color]
        dp = [[[1e9+7 for k in range(n+1)] for j in range(m+1)] for i in range(target+1)]
        for j in range(n+1):
            dp[0][0][j] = 0
        
        for i in range(1, target+1):
            for j in range(i, m+1):
                sk, sj, ek, ej =  1, 1, n, n
                if houses[j-1] != 0:
                    sj = houses[j-1]
                    ej = houses[j-1]
                    
                if j >= 2 and houses[j-2] != 0:
                    sk = houses[j-2]
                    ek = houses[j-2]
                elif j == 1:
                    sk = 0
                    ek = 0
                    
                for ci in range(sj, ej+1):
                    paint_cost = 0
                    if ci != houses[j-1]: # not painted
                        paint_cost = cost[j-1][ci-1]
                    for cj in range(sk, ek+1):
                        if ci == cj:
                            dp[i][j][ci] = min(dp[i][j][ci], dp[i][j-1][cj] + paint_cost)
                        else:
                            dp[i][j][ci] = min(dp[i][j][ci], dp[i-1][j-1][cj] + paint_cost)
                
        ans = min(dp[target][m])
        if ans == 1e9+7 :
            ans = -1
        return ans
