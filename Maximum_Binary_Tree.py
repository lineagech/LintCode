# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if len(nums) == 0: 
            return None
        
        max_val = max(nums)
        maxNode = TreeNode(max_val)
        
        maxNode.left = self.constructMaximumBinaryTree(nums[0:nums.index(max_val)])
        maxNode.right = self.constructMaximumBinaryTree(nums[nums.index(max_val)+1:])
        
        return maxNode
