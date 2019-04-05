# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def dfs(root):
            if not root: return 0
            left, right = dfs(root.left), dfs(root.right)
            self.ans += abs(left - right)
            return root.val + left + right

        dfs(root)

        return self.ans