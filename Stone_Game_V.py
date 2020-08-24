class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        presum = [0 for i in range(n)]
        for i, val in enumerate(stoneValue):
            presum[i] = val if i == 0 else (presum[i-1]+val)
        
        @lru_cache(None)
        def dp(l, r):
            if l == r:
                return 0
            max_val = 0
            for i in range(l, r):
                l_sum = presum[i]-presum[l-1] if l > 0 else presum[i]
                r_sum = presum[r]-presum[i]
                
                if l_sum < r_sum:
                    max_val = max(max_val, l_sum + dp(l, i))
                elif r_sum < l_sum:
                    max_val = max(max_val, r_sum + dp(i+1, r))
                else:
                    max_val = max(max_val, l_sum + max(dp(l, i), dp(i+1, r)))
            return max_val
        
        return dp(0, n-1)
