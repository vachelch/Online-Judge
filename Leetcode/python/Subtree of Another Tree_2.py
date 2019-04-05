class Solution:
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        if s == None: return False
        if self.isSame(s, t): return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)


    def isSame(self, s, t):
    	if s == None and t == None: return True
        if s.val != t.val: return False
        if s == None or t == None: return False
        return self.isSame(s.left, t.left) and self.isSame(s.right, t.right)
