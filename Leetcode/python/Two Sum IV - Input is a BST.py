class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        self.result = False
        self.dic = set()
        self.findSum(self, root, k)

        return self.result

    def findSum(self, root, k):
    	if k - root.val in self.dic:
    		self.result = True
    	else:
    		if root.val not in self.dic:
    			self.dic.add(root.val)
    		if root.left:
    			self.findSum(root.left, k)
    		if root.right:
    			self.findSum(root.right, k)

