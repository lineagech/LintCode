class Solution:
    def PredictTheWinner(self, nums: 'List[int]') -> 'bool':
        ## dp[i][j] = max( nums[i]+min(dp[i-2][j], dp[i-1][j-1]), 
        ##                 nums[j]+min(dp[i][j-2], dp[i-1][j-1]) )
        n = len(nums)
        if n == 0: return True
        total = sum(nums[:])
        dp = [ [0]*n for _ in range(n) ]
        
        ## Initialize
        for i, val in enumerate(nums):
            dp[i][i] = val
            if i < n-1:
                dp[i][i+1] = max(val, nums[i+1])
        
        for l in range(3,n+1):
            for s in range(n):
                e = s+l-1
                if e < n:
                    dp[s][e] = max( nums[s]+min(dp[s+2][e], dp[s+1][e-1]), 
                                    nums[e]+min(dp[s][e-2], dp[s+1][e-1]) )
                    print(dp[s][e], s, e)
                else: break

        return dp[0][n-1] >= total/2
