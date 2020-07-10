class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        # (digit, len)
        dp = [(-1,-1) for i in range(target+1)]
        
        dp[0]=(0,0)
        for t in range(1, target+1):
            for d in range(1, 10):
                c = cost[d-1]
                if t < c or dp[t-c][0] == -1 or dp[t-c][1]+1 < dp[t][1]:
                    continue
                dp[t] = (d, dp[t-c][1]+1) # last digit and total length
        
        if dp[target][1] == -1:
            return "0"
        ans = ""
        while target > 0:
            ans += str(dp[target][0])
            target -= cost[dp[target][0]-1]
        
        return ans
