class Solution:
    class UnionFind:
        def __init__(self, n):
            self.p = defaultdict(int)
            self.d = defaultdict(int)
            for i in range(n):
                self.p[i] = i
                self.d[i] = 1
            
        def root(self, node):
            if self.p[node] != node:
                pp = self.root(self.p[node])
                self.p[node] = pp
            return self.p[node]
        
        def union(self, n1, n2):
            p1 = self.root(n1)
            p2 = self.root(n2)
            if p1 == p2:
                return False
            if self.d[p1] < self.d[p2]:
                self.p[p1] = p2
            elif self.d[p1] > self.d[p2]:
                self.p[p2] = p1
            else:
                self.p[p1] = p2
                self.d[p2] += 1
            return True
    
    def MST(self, n, edges, ex_edge=-1, in_edge=-1):
        un = self.UnionFind(n)
        min_weights = 0
        edge_count = 0
        if in_edge != -1:
            un.union(edges[in_edge][0], edges[in_edge][1])
            min_weights += edges[in_edge][2]
            edge_count += 1
            edges.pop(in_edge)
        if ex_edge != -1:
            edges.pop(ex_edge)
    
        for edge in edges:
            src = edge[0]
            dst = edge[1]
            if un.union(src, dst):
                min_weights += edge[2]
                edge_count += 1
                
        if edge_count != n-1:
            return sys.maxsize
        
        return min_weights
    
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        if n <= 1:
            return [[], []]
        for i in range(len(edges)):
            edges[i].append(i)
        sorted_edges = sorted(edges, key=operator.itemgetter(2))
        min_weights = self.MST(n, list(sorted_edges), -1, -1)
        critical = []
        pseudo_critical = []
        
        for i, edge in enumerate(sorted_edges):
            if self.MST(n, list(sorted_edges), i, -1) > min_weights:
                critical.append(edge[3])
            elif self.MST(n, list(sorted_edges), -1, i) == min_weights:
                pseudo_critical.append(edge[3])
        
        return [critical, pseudo_critical]
