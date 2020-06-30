class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        l = [0]*len(nums)
        r = [0]*len(nums)
        ans = 0
        for i, v in enumerate(nums):
            if i == 0:
                l[i] = nums[i]
                r[len(nums)-1-i] = nums[len(nums)-1-i]
            else:
                l[i] = (l[i-1]+1) * nums[i]
                r[len(nums)-i-1] = (r[len(nums)-i]+1) * nums[len(nums)-i-1]
        
        for i, v in enumerate(nums):
            if i == 0:
                ans = max(ans, r[i+1])
            elif i == len(nums)-1:
                ans = max(ans, l[i-1])
            else:
                ans = max(ans, l[i-1]+r[i+1])
        
        return ans
