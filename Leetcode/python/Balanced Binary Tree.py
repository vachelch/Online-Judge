# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None: return True
        self.is_balanced = 1
        def depth(root):
            if root == None: return 0
            left, right = depth(root.left), depth(root.right)
            if self.is_balanced:
                self.is_balanced = (abs(left - right) <= 1)
            return 1 + max(left, right)
        depth(root)

        return self.is_balanced
