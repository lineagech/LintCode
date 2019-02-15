class Solution:
    def shortestSuperstring(self, A: 'List[str]') -> 'str':
        n = len(A)
        # dp[i][j] = min{ dp[i-2^j][k]+cost[k][j] } 
        cost = [[0]*n for j in range(n)]
        for i in range(n):
            for j in range(n):
                cost[i][j] = len(A[j])
                if i == j: continue
                for k in range(min(len(A[i]), len(A[j]))):
                    if A[i][len(A[i])-k-1:] == A[j][:k+1]:
                        cost[i][j] = len(A[j])-1-k
            
        dp = [[sys.maxsize]*n for _ in range(1<<n)]
        parent = [[0]*n for _ in range(1<<n)]
        for i in range(n):
            dp[0][i] = 0
            dp[(1<<i)][i] = cost[i][i]
        
        for mask in range(1,1<<n):
            for bit in range(n):
                if mask & (1<<bit):
                    prev_mask = mask ^ (1<<bit)
                    for k in range(n):
                        if prev_mask & (1<<k):
                            if dp[mask][bit] > dp[prev_mask][k]+cost[k][bit]:
                                dp[mask][bit] = dp[prev_mask][k]+cost[k][bit]
                                parent[mask][bit] = k


        path = []                        
        end_one = min(range(n), key=dp[-1].__getitem__)
        mask = (1<<n) - 1
        while mask != 0:
            path.append(end_one)
            mask, end_one = mask^(1<<end_one), parent[mask][end_one]
        
        path = path[::-1]
        ans = A[path[0]]
        for i in range(1, len(path)):
            non_overlap = cost[path[i-1]][path[i]] 
            ans += A[path[i]][len(A[path[i]])-non_overlap:]
        return ans
        
        
    
