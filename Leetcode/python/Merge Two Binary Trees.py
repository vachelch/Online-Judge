class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1 == None and t2 == None: return None
        elif t1 and t2:
        	t1.val = t1.val + t2.val
        	t1.left = self.mergeTrees(t1.left, t2.left)
        	t1.right = self.mergeTrees(t1.right, t2.right)

       	elif t2:
       		t1 = t2

       	return t1
