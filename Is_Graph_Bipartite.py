class Solution:
    def isBipartite(self, graph: 'List[List[int]]') -> 'bool':
        sets = [set(),set()]
        index = 0
        queue = collections.deque([])
        if( len(graph) == 0 ) : return True

        for k in range(len(graph)):
            if len(graph[k]) == 0: continue
            if k in sets[0] or k in sets[1]:
                continue
            sets[index].add(k)
            queue.append(k)
            while len(queue) != 0:
                queue_len = len(queue)
                for i in range(queue_len):
                    node = queue.popleft()
                    for j in graph[node]:
                        if node in sets[index] and j in sets[index]:
                            return False
                        if j not in sets[index^1]:
                            sets[index^1].add(j)
                            queue.append(j)
                index ^= 1
        return True
