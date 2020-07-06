class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        m = len(nums1)
        n = len(nums2)
        l = min(m,n)
    
        dp = [[-1e9 for k in range(n+1)] for j in range(m+1)]
    
        for i in range(1,m+1):
            for j in range(1,n+1):
                dp[i][j] = nums1[i-1]*nums2[j-1]
        ans = -1*sys.maxsize-1
        for i in range(1, m+1):
            for j in range(1, n+1):
                v = nums1[i-1]*nums2[j-1]
                dp[i][j] = max(dp[i-1][j-1] + (v if v >= 0 else 0) , 
                               dp[i-1][j],
                               dp[i][j-1],
                               dp[i][j])
                ans = max(ans, dp[i][j])
    
        return ans
