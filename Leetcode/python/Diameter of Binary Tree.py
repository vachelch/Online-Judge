# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max = 0
        def max_len(root):
        	if root == None: return 0
        	if root.left == None and root.right == None: return 0

        	left, right = max_len(root.left),  max_len(root.right)
        	if root.left and root.right:
        		self.max = max(self.max, 2 + left + right)
        	elif root.left:
        		self.max = max(self.max, 1 + left)
        	elif root.right:
        		self.max = max(self.max, 1 + right)

        	return 1 + max(left, right)

        max_len(root)

        return self.max