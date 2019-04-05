# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None 

class Solution:

    def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.pi = {}
        self.max_depth = 0
        self.nodes = []

        def DFS(root, depth, pi):
            if root != None:
                if depth == self.max_depth:
                    self.nodes.append(root)
                if depth > self.max_depth:
                    self.nodes = [root]
                    self.max_depth = depth
                self.pi[root] = pi
                DFS(root.left, depth+1, root)
                DFS(root.right, depth+1, root)


        DFS(root, 0, None)

        if len(self.nodes) <= 1:
            return self.nodes[0]

        # print(self.nodes)

        while (1):
            tmp_pi = set()
            for node in self.nodes:
                tmp_pi.add(self.pi[node])

            self.nodes = list(tmp_pi)
            if len(self.nodes) == 1:
                break

        return self.nodes[0]





