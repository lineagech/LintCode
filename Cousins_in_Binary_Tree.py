# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: 'TreeNode', x: 'int', y: 'int') -> 'bool':
        self.x_depth = 0
        self.y_depth = 0
        self.x_parent = None
        self.y_parent = None
        def find_x_y(curr, curr_depth):
            if curr == None: return
            if curr.left != None or curr.right != None :
                if curr.left != None and curr.left.val == x or curr.right != None and curr.right.val == x:
                    self.x_depth = curr_depth + 1
                    self.x_parent = curr
                if curr.left != None and curr.left.val == y or curr.right != None and curr.right.val == y:
                    self.y_depth = curr_depth + 1
                    self.y_parent = curr
            find_x_y(curr.left, curr_depth+1)
            find_x_y(curr.right, curr_depth+1)
                
        find_x_y(root, 0)
        return self.x_depth==self.y_depth and self.x_parent!=self.y_parent
