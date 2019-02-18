class Solution:
    def minKBitFlips(self, A: 'List[int]', K: 'int') -> 'int':
        flip_nums = [0]*(len(A)+1)
        current = 0
        ans = 0
        for i, val in enumerate(A):
            current += flip_nums[i]
            if (val+current) % 2 == 0:
                A[i] = 1
                current += 1
                ans += 1
                if i+K <= len(A):
                    flip_nums[i+K] -= 1
                else:
                    return -1
        return ans        
