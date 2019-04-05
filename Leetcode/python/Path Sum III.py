# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if root == None: return 0
        def count_sum(root, sum):
        	if root == None:
        		return 0
        	count = 0
        	if root.val == sum:
        		count += 1
        	count = count + count_sum(root.left, sum - root.val) + count_sum(root.right, sum - root.val)
        	return count

        return count_sum(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)





root = TreeNode(1)
x2 = TreeNode(2)
x3 = TreeNode(3)
x4 = TreeNode(4)
x5 = TreeNode(5)

root.right = x2
x2.right = x3
x3.right = x4
x4.right = x5

s = Solution()
print(s.pathSum(root, 3))









