class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        return self.tree_to_str(t)

    def tree_to_str(self, t):
        if t == None: return ''

        str_ = str(t.val)
        str_left = '(' + self.tree_to_str(t.left) + ')'
        str_right = '(' + self.tree_to_str(t.right) + ')'
        if str_left == '()' and str_right == '()':
            return str_
        elif str_right == '()':
            return str_ + str_left
        else:
           return str_ + str_left + str_right


######best#######
# class Solution:
#     def tree2str(self, t):
#         """
#         :type t: TreeNode
#         :rtype: str
#         """
#         if not t: return ''
#         if not t.left and not t.right: return str(t.val)
#         if not t.left: return str(t.val)+'()('+self.tree2str(t.right)+')'
#         if not t.right: return str(t.val)+'('+self.tree2str(t.left)+')'
#         else: return str(t.val)+'('+self.tree2str(t.left)+')('+self.tree2str(t.right)+')'