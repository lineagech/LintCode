# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: 'TreeNode') -> 'List[List[int]]':
        visited = collections.defaultdict(lambda: collections.defaultdict(list))
        
        def dfs(node, x=0, y=0):
            if node:
                visited[x][y].append(node)
                dfs(node.left, x-1, y+1)
                dfs(node.right, x+1, y+1)
        dfs(root)
        ans = []
        
        for col in sorted(visited):
            report = []
            for row in sorted(visited[col]):
                report.extend( sorted([n.val for n in visited[col][row]]) )
            ans.append(report)    
        
        return ans
