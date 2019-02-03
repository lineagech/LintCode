class Solution:
    def leastOpsExpressTarget(self, x, target):
        """
        :type x: int
        :type target: int
        :rtype: int
        """
        priority_queue = []
        visited_set = set()
        heapq.heappush(priority_queue,(0,target))
        
        while len(priority_queue) != 0:
            c, t = heapq.heappop(priority_queue)
            if t == 0: 
                return int(c-1)
            k = (math.log(t))//(math.log(x))
            if t in visited_set: 
                continue
            visited_set.add(t)
            
            next_t = t-math.pow(x,k)
            if next_t not in visited_set:
                heapq.heappush( priority_queue, (c+(2 if k == 0 else k), next_t) )
            
            next_t = math.pow(x,k+1)-t
            if next_t not in visited_set:           
                heapq.heappush( priority_queue, (c+(k+1), next_t) )
                          
        return -1
