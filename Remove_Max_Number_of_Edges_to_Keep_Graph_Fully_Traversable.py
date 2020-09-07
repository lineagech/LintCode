class Solution:
    class Conn:
        def __init__(self, n: int):
            self.p = [i for i in range(n+1)]
            self.e = 0
        def __len__(self):
            return self.e
        def find(self, x):
            if self.p[x] != x: 
                self.p[x] = self.find(self.p[x])
            return self.p[x]
        
        def connect(self, x, y):
            rx, ry = self.find(x),  self.find(y)
            if rx == ry:
                return 1
            self.p[rx] = ry
            self.e += 1
            return 0
        
        
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        A_conn = self.Conn(n)
        B_conn = self.Conn(n)
        ans = 0        
        
        for t, x, y in edges:
            if t != 3:
                continue
            ans += A_conn.connect(x,y)
            B_conn.connect(x,y)
        
        for t, x, y in edges:
            if t == 3: 
                continue
            if t == 1:
                ans += A_conn.connect(x,y)
            else:
                ans += B_conn.connect(x,y)

        return ans if A_conn.e == B_conn.e == n-1 else -1
