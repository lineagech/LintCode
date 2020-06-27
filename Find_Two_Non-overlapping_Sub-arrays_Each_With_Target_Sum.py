class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        s = 0
        min_lens = [-1] * len(arr)
        curr_min_len = sys.maxsize
        ans = sys.maxsize
        sub_sum = 0
        
        if len(arr) <= 2 or target < 0:
            return -1
        
        for e in range(len(arr)):
            sub_sum += arr[e]
            while (sub_sum > target):
                sub_sum -= arr[s]
                s += 1
            if sub_sum == target:
                if s > 0 and min_lens[s-1] != -1:
                    ans = min(ans, min_lens[s-1] + (e-s+1))
                curr_min_len = min(curr_min_len, e-s+1)
            min_lens[e] = curr_min_len            
        
        if ans == sys.maxsize:
            return -1
        
        return ans
