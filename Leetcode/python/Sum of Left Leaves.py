# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None: return 0

        def traverse(root, cond):
            if root == None: return 0

            sum_ = 0
            if cond == 1:
                if root.left == None and root.right == None:
                    sum_ += root.val
                else:
                    if root.left:
                        sum_ += traverse(root.left, 1)
                    if root.right:
                        sum_ += traverse(root.right, 0)

            else:
                if root.left:
                    sum_ += traverse(root.left, 1)
                if root.right:
                    sum_ += traverse(root.right, 0)

            return sum_

        return traverse(root.left, 1) + traverse(root.right, 0)







