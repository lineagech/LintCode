# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        self.level_start = []
        return self.dfs(root, 0, 0)
        
    def dfs(self, root: TreeNode, depth: int, identifier: int):
        if root == None:
            return 0
        if len(self.level_start) == depth:
            self.level_start.append(identifier)
        
        return max(identifier-self.level_start[depth]+1,
            max( self.dfs(root.left, depth+1, (identifier-self.level_start[depth])*2),
                 self.dfs(root.right, depth+1, (identifier-self.level_start[depth])*2+1)))
