class Solution:
    def countSumOfK(self, nums, k):
        total_sum = 0
        total_count = 0
        start = 0
        curr_sum = 0
        curr = 0
        for end in range(len(nums)):
            curr += nums[end]
            curr_sum += (end-start+1)*nums[end]
            while curr > k:
                curr_sum -= curr
                curr -= nums[start]
                start += 1
            total_sum += curr_sum
            total_count += (end-start+1)
        
        return (total_count, total_sum)
    
    def sumOfFirstK(self, nums, k):
        l = self.min_sum
        r = self.max_sum
        if k == 0:
            return 0
        while(l < r):
            mid = (l+r)//2
            res = self.countSumOfK(nums, mid)
            if res[0] >= k:
                r = mid
            else:
                l = mid+1
        
        res = self.countSumOfK(nums, r)
        return res[1]
    
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        kMod = 1e9 + 7
        self.min_sum = min(nums)
        self.max_sum = sum(nums)
        return int((self.sumOfFirstK(nums, right) - self.sumOfFirstK(nums, left-1)) % kMod)
            
