# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def intervalIntersection(self, A: 'List[Interval]', B: 'List[Interval]') -> 'List[Interval]':
        pA = 0
        pB = 0
        ans = []
        while pA < len(A) and pB < len(B):
            while pA<len(A) and pB<len(B) and (B[pB].end < A[pA].start or A[pA].end < B[pB].start):
                if A[pA].end < B[pB].start:
                    pA += 1
                elif B[pB].end < A[pA].start:
                    pB += 1
            if pA >= len(A) or pB >= len(B): break
            ans.append( Interval(max(A[pA].start, B[pB].start), min(A[pA].end, B[pB].end)) )
            if A[pA].end < B[pB].end:
                pA += 1
            else:
                pB += 1
        return ans
