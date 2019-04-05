# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None: return True
        def is_symmetric(A, B):
        	if A == None and B == None: return True
        	if A and B and A.val == B.val:
        		return is_symmetric(A.left, B.right) and is_symmetric(A.right, B.left)
        	return False

        return is_symmetric(root.left, root.right)
