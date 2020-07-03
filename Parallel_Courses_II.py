class Solution:
    def minNumberOfSemesters(self, n: int, dependencies: List[List[int]], k: int) -> int:
        # dp[s]: min day under the state s
        S = 1<<n
        deps = defaultdict(int)
        for i in range(n):
            deps[i] = 0
        for dep in dependencies:
            deps[dep[1]-1] |= (1<<dep[0]-1)
        
        dp = [sys.maxsize] * S
        dp[0] = 0
        for s in range(S):
            if dp[s] == sys.maxsize: 
                continue
            mask = 0
            for i in range(n):
                if (not s & (1<<i)) and ((s & deps[i]) == deps[i]) :
                    mask |= (1<<i)
            if mask == 0: 
                continue
            # mask if all of the courses which can be taken regardless of k
            if bin(mask).count("1") <= k:
                dp[s|mask] = min(dp[s|mask], dp[s]+1)
            else:
                # try all of the subsets of mask --> important techniques!
                sub_mask = mask
                while sub_mask != 0:
                    if bin(sub_mask).count("1") <= k:
                        dp[s|sub_mask] = min(dp[s|sub_mask], dp[s]+1)
                    sub_mask = (sub_mask-1) & mask
                
        return dp[-1]

        
