class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[[-1 for i in range(n)] for j in range(n)] for k in range(m)]
        #print(dp)
        # initial state
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1]
        
        for row in range(1, m):
            for c1 in range(n):
                for c2 in range(n):
                    #print(row,c1,c2, dp[row][c1][c2])
                    curr_num = max(dp[row-1][c1-1][c2-1] if c1>0 and c2 else -1,
                                   dp[row-1][c1-1][c2] if c1>0 else -1,
                                   dp[row-1][c1-1][c2+1] if c1>0 and c2<n-1 else -1,
                                   dp[row-1][c1][c2-1] if c2>0 else -1,
                                   dp[row-1][c1][c2],
                                   dp[row-1][c1][c2+1] if c2<n-1 else -1,
                                   dp[row-1][c1+1][c2-1] if c1<n-1 and c2>0 else -1,
                                   dp[row-1][c1+1][c2] if c1<n-1 else -1,
                                   dp[row-1][c1+1][c2+1] if c1<n-1 and c2<n-1 else -1)
                    if curr_num == -1: # not reachable
                        dp[row][c1][c2] = -1
                        continue
                    if c1 == c2:
                        dp[row][c1][c2] = curr_num + grid[row][c1]
                    else:
                        dp[row][c1][c2] = curr_num + grid[row][c1] + grid[row][c2]
            #print(dp[row])
                        
        return max(list(itertools.chain.from_iterable(dp[m-1])))                
        
