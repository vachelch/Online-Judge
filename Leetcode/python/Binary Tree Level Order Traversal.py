# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import queue
class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None: return []
        q = queue.Queue()
        q.put(root)
        res = []

        while not q.empty():
            level = []
            l = q.qsize()
            for i in range(l):
                node = q.get()
                level.append(node.val)
                if node.left:
                    q.put(node.left)
                if node.right:
                    q.put(node.right)
            res.insert(0,level)
        return res















