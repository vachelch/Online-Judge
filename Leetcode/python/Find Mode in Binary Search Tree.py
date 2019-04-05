# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None: return []

        self.count = {}
        self.max = 0
        def helper(root):
            if root != None:
                if root.val in self.count:
                    self.count[root.val] += 1
                else:
                    self.count[root.val] = 1
                self.max = max(self.count[root.val], self.max)
                helper(root.left)
                helper(root.right)

        helper(root)

        elements = []
        for key, val in self.count.items():
            if val == self.max:
                elements.append(key)

        return elements






