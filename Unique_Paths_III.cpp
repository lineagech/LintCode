class Solution:

    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        if m == 0:  return 0
        n = len(grid[0])
        
        # dp[r][c][target]
        def coded_bit(i, j):
            return (1<<(n*i+j))
        
        def next_dir(i, j):
            for ni, nj in ((i+1,j), (i-1,j), (i,j+1), (i,j-1)):
                if ni>=0 and ni<m and nj>=0 and nj<n and grid[ni][nj]%2==0:
                    yield (ni, nj)
        state = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if( val % 2 == 0 ):
                    state |= coded_bit(i,j)
                if( val == 2 ):
                    target_i, target_j = i, j
                elif( val == 1 ):
                    source_i, source_j = i, j
        
        def dp(curr_i, curr_j, state):
            if curr_i==target_i and curr_j==target_j:
                return (state == 0)
            ans = 0
            for next_i, next_j in next_dir(curr_i, curr_j):
                if state & coded_bit(next_i,next_j): 
                    ans += dp(next_i, next_j, state^coded_bit(next_i, next_j))
            return ans
        
        return dp(source_i, source_j, state)
        
        
