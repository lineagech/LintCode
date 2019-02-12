class Solution:
    def equationsPossible(self, equations: 'List[str]') -> 'bool':
        root = collections.defaultdict(str)
        
        def find(a):
            if a == root[a]: return a
            root[a] = find(root[a])
            return root[a]
        
        def union(a, b):
            root_a = find(a)
            root_b = find(b)
            if root_a != root_b:
                root[root_b] = root_a
        
        for equation in equations:
            if(root[equation[0]]==""): root[equation[0]] = equation[0]
            if(root[equation[3]]==""): root[equation[3]] = equation[3]
            if equation[1] == "=":
                union(equation[0], equation[3])
                
        for equation in equations:
            if equation[1] == "!":
                if find(equation[0]) == find(equation[3]): 
                    return False
                
        return True
