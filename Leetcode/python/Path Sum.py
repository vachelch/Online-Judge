# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root == None: return False
        def helper(root, sum):
            if root.left == None and root.right == None:
                if sum == root.val: return True
                else: return False
            elif root.left and root.right:
                return helper(root.left, sum - root.val) or helper(root.right, sum - root.val)
            elif root.left:
                return helper(root.left, sum - root.val)
            else:
                   return helper(root.right, sum - root.val)

        return helper(root, sum)