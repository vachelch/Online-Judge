# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None: return []

        def traverse(root, level):
        	if level in self.result:
        		self.result[level].append(root.val)
        	else:
        		self.result[level] = [root.val]

        	if root.left:
        		traverse(root.left, level+1)
        	if root.right:
        		traverse(root.right, level+1)

        self.result = {}
        traverse(root, 0)
        result = []
        for i in range(len(self.result)):
        	result.insert(0, self.result[i])

        return result

root = TreeNode(3)
x21 = TreeNode(9)
x22 = TreeNode(20)
x31 = TreeNode(15)
x32 = TreeNode(7)

root.left = x21
root.right = x22
x22.left = x31
x22.right = x32

s = Solution()
print(s.levelOrderBottom(root))





































