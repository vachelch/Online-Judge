# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root == None: return []
        self.all_path = []
        def traverse(root, path):
        	if root.left == None and root.right == None:
        		path += str(root.val)
        		self.all_path.append(path)
        	else:
        		path = path + str(root.val) + "->"
        		if root.left: traverse(root.left, path)
        		if root.right: traverse(root.right, path)

        traverse(root, "")
        return self.all_path