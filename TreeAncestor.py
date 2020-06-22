class TreeAncestor:
    node_num = 0
    graph = defaultdict(list)
    node_path = defaultdict(lambda: defaultdict(int))
    
    def __init__(self, n: int, parent: List[int]):
            if n <= 0 or len(parent) == 0: 
                return
            for i in range(len(parent)):
                self.graph[i] = []
            for i, v in enumerate(parent):
                if not (v>=0 and v<n):
                    continue;
                self.graph[v].append(i)
                
            self.node_num = n
            path = []
            self.gen_path(0, path)
            
    def getKthAncestor(self, node: int, k: int) -> int:
        if node >= self.node_num or k >= self.node_num:
            return -1
        if k <= 0:
            return node
        m = 1 << (len(self.node_path[node].keys()))
        print(node, k, m)
        if k >= m:
            return -1
        msb_pos = int(math.floor(math.log(k,2)))
        return self.getKthAncestor(self.node_path[node][1<<msb_pos], k-(1<<msb_pos))
        
            
    def gen_path(self, node: int, path: list):
        i = 1
        self.node_path[node].clear()
        while i <= len(path):
            self.node_path[node][i] = path[len(path)-i]
            i *= 2
        path.append(node)
        for child in self.graph[node]:
            self.gen_path(child, path)
        path.pop()
# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
