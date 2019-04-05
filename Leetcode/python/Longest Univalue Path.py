class Solution:
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        self.UnivaluePath(root)
        return self.ans
     
    def UnivaluePath(self, root):
	    if root == None: return 0

	    l= self.UnivaluePath(root.left)
	    r= self.UnivaluePath(root.right)

	    pr = 0
	    pl = 0

	    if root.left != None and root.val == root.left.val: pl = l + 1

	    if root.right != None and root.val == root.right.val: pr = r + 1
	    
	    self.ans = max(self.ans, pl + pr)

	    return max(pl, pr)




