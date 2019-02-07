class Solution:
    def regionsBySlashes(self, grid: 'List[str]') -> 'int':
        N = len(grid)
        root = collections.defaultdict(list)
        for i in range(N):
            for j in range(N):
                for k in range(4):
                    root[i*4*N+j*4+k] = i*4*N+j*4+k
        
        def find(node):
            tmp = node
            while root[tmp] != tmp:
                tmp = root[tmp]
            root[node] = tmp
            return tmp
        def union(n1, n2):
            r1 = find(n1)
            r2 = find(n2)
            if( r1 != r2 ): root[r2] = r1
        
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                base = i*4*N+j*4
                if val in " /":
                    union(base+0, base+1)
                    union(base+2, base+3)
                if val in "\\ ":
                    union(base+0, base+3)
                    union(base+1, base+2)
                    
                if i-1 >= 0:
                    union(base+0, base-4*N+2)
                if i+1 < N:
                    union(base+2, base+4*N+0)
                
                if j-1 >= 0:
                    union(base+1, base-4+3)
                if j+1 < N:
                    union(base+3, base+4+1)
                    
        return sum( root[i]==i for i in range(4*N*N) )
