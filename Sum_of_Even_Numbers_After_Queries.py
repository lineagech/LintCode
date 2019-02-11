class Solution:
    def sumEvenAfterQueries(self, A: 'List[int]', queries: 'List[List[int]]') -> 'List[int]':
        even_sum = sum( filter(lambda x: x%2==0, A) )
        is_even = [val%2 == 0 for val in A]
        ans = []
        for query in queries:
            val = query[0]
            index = query[1]
            if A[index] % 2 == 0:
                if val % 2 == 0: even_sum += val
                else: even_sum -= (A[index])
            else:
                if val % 2 == 1: even_sum += (val + A[index])
            A[index] += val
            ans.append(even_sum)
        return ans
