class Solution:
    def countTriplets(self, A: 'List[int]') -> 'int':
        max_val = max(A)
        val_hash = [ 0 for i in range(max_val+1) ]
        for i in range(len(A)):
            for j in range(len(A)):
                val_hash[ A[i] & A[j] ] += 1
        
        ans = 0
        for i in range(len(A)):
            for k in range(len(val_hash)):
                if A[i] & k == 0: ans += val_hash[k]
        
        return ans
