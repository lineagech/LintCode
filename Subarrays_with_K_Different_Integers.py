class Solution:
    def subarraysWithKDistinct(self, A: 'List[int]', K: 'int') -> 'int':
        def subarray_exact_num(k:'int'):
            result = 0
            start = 0
            count = collections.defaultdict(int)
            for end in range(len(A)):
                if count[A[end]] == 0:
                    k -= 1
                count[A[end]] += 1
                while k < 0:
                    count[A[start]] -= 1
                    if count[A[start]] == 0:
                        k += 1
                    start += 1
                result += (end-start+1)
            return result
        print(subarray_exact_num(K))
        return subarray_exact_num(K)-subarray_exact_num(K-1)
