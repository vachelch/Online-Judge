class Solution:
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        self.node = [None]
        self.find_node(s, t.val)
        sum_ = 0
        for node in self.node:
            self.is_sub = 1
            self.is_same(node, t)
            sum_ += self.is_sub
        if sum_:
            return True
        else:
            return False

    def find_node(self, s, value):
        if s.val == value:
            self.node.append(s)

        if s.left:
            self.find_node(s.left, value)

        if s.right:
            self.find_node(s.right, value)

    def is_same(self, s, t):
        if s == None: self.is_sub = 0
        else:
            if s.val != t.val:
                self.is_sub = 0

            if s.left and t.left:
                self.is_same(s.left, t.left)

            if s.right and t.right:
                self.is_same(s.right, t.right)

            if (s.right and t.right == None) or (s.left and t.left == None) or (s.left == None and t.left) or (s.right == None and t.right):
                self.is_sub = 0


















