# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        self.sum_dic = {}
        self.count = {}
        self.averageLevels(root, 1)

        average = []
        for key, value in self.sum_dic.items():
        	average.append(value/self.count[key])
        return average

    def averageLevels(self, root, level):
    	if level not in self.sum_dic:
    		self.sum_dic[level] = 0
    		self.count[level] = 0

    	self.sum_dic[level] += root.val
    	self.count[level] += 1

    	if root.left:
    		self.averageLevels(root.left, level+1)
    	if root.right:
    		self.averageLevels(root.right, level+1)































