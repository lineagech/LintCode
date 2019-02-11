# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    index_dict = "abcdefghijklmnopqrstuvwxyz" 
    def smallestFromLeaf(self, root: 'TreeNode') -> 'str':
        if root == None:
            return ""
        left_str = self.smallestFromLeaf(root.left)
        right_str = self.smallestFromLeaf(root.right)
        if left_str == "" or right_str =="":
            return (left_str if right_str=="" else right_str) + self.index_dict[root.val]
        return "".join((min(left_str, right_str), self.index_dict[root.val]))
    
