class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        ## dp[row][col][c] = dp[row+1][col][c-1] + dp[row][col+1][c-1]
        self.kMod = 1e9+7
        self.m = len(pizza)
        self.n = len(pizza[0])
        self.apples = [[0 for j in range(self.n+1)] for i in range(self.m+1)]
        self.caches = [[[-1 for l in range(k+1)] for j in range(self.n)] for i in range(self.m)]
        
        for i in range(self.m):
            for j in range(self.n):
                self.apples[i+1][j+1] = self.apples[i][j+1] + self.apples[i+1][j] \
                                  - self.apples[i][j] + (1 if pizza[i][j]=='A' else 0)
                
        return self.dfs(0, 0, k-1)
        
    def hasApple(self, x0: int, y0: int, x1: int, y1: int):
        return (self.apples[x1+1][y1+1] - self.apples[x1+1][y0] - self.apples[x0][y1+1] + self.apples[x0][y0]) > 0
    
    
    def dfs(self, x: int, y: int, k: int):
        if k == 0:
            return (1 if self.hasApple(x, y, self.m-1, self.n-1) else 0)
        
        if self.caches[x][y][k] != -1: 
            return self.caches[x][y][k]
        
        ans = 0
        for nx in range(x, self.m-1):
            ans = (ans+int(self.dfs(nx+1, y, k-1) * (1 if self.hasApple(x, y, nx, self.n-1) else 0))) % self.kMod
            
        for ny in range(y, self.n-1):
            ans = (ans+int(self.dfs(x, ny+1, k-1) * (1 if self.hasApple(x, y, self.m-1, ny) else 0))) % self.kMod
        
        self.caches[x][y][k] = int(ans)
    
        return self.caches[x][y][k]
