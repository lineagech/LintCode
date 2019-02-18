class Solution:
    def numSquarefulPerms(self, A: 'List[int]') -> 'int':
        n = len(A)
        dp = [ [0]*n for _ in range((1<<n))]
        g = [[0]*n for _ in range(n)]
        
        # dp[s][i]: # of ways to reach state s and ends with i
        # dp[s|(1<<j)][j] += dp[s][i] if g[i][j]
        A.sort()
        # determine g[i][j]
        for i in range(n):
            for j in range(i+1,n):
                m = A[i]+A[j]
                r = int(math.sqrt(m))
                if r*r == m:
                    g[i][j] = g[j][i] = 1
        
        # Initialize
        for i, val in enumerate(A):
            if i==0 or A[i] != A[i-1]:
                dp[(1<<i)][i] = 1

        for s in range(1,1<<n):
            for i in range(n):
                if dp[s][i] == 0: continue
                for j in range(n):
                    # not square
                    if g[i][j] == 0: continue
                    # visited
                    if s & (1<<j): continue
                    if j > 0 and not(s & (1<<(j-1))) and A[j]==A[j-1]: continue
                    dp[s|(1<<j)][j] += dp[s][i]
                
        return sum(dp[(1<<n)-1][:])
