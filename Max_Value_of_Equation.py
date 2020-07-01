class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        queue = []
        queue.append((points[0][1]-points[0][0], points[0][0]))
        ans = -sys.maxsize-1
        
        for p in points[1:]:
            while len(queue) > 0 and p[0]-queue[0][1] > k:
                queue.pop(0)
            if len(queue) > 0:
                ans = max(ans, queue[0][0]+p[0]+p[1])
            new_key = p[1]-p[0]
            while len(queue) > 0 and new_key >= queue[-1][0]:
                queue.pop(-1)
            queue.append((new_key, p[0]))
            
        return ans
