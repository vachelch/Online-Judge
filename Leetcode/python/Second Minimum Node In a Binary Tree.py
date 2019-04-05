# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.first = root.val
        self.second = None

        self.search_binary(root)

        if self.second == None:
            return -1
        else:
            return self.second

    def search_binary(self, root):
        if self.second == None:
            if root.val > self.first:
                self.second = root.val
            elif root.val < self.first:
                self.second = self.first
                self.first = root.val

        else:
            if root.val < self.first:
                self.second = self.first
                self.first = root.val
            elif self.first < root.val < self.second:
                self.second = root.val

        if root.left:
            self.search_binary(root.left)
            self.search_binary(root.right)




x1 = TreeNode(5)
x21 = TreeNode(8)
x22 = TreeNode(5)
# x31 = TreeNode(5)
# x32 = TreeNode(5)


# x22.left = x31
# x22.right = x32
x1.left = x21
x1.right = x22


s = Solution()
print(s.findSecondMinimumValue(x1))

































