# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, x):
# #         self.val = x
# #         self.left = None
# #         self.right = None

# class AdjNode:
#     def __init__(self, x):
#         self.ptr = x
#         self.adj_list = []
#         self.visited = 0
#         self.dist = 0

# class Solution:
#     def traverse(self, root, target, node):
#         if node.ptr == target:
#             self.tar_node = node
#         if root.left:
#             left_node = AdjNode(root.left)

#             node.adj_list.append(left_node)
#             left_node.adj_list.append(node)

#             self.traverse(root.left, target, left_node)
#         if root.right:
#             right_node = AdjNode(root.right)

#             node.adj_list.append(right_node)
#             right_node.adj_list.append(node)

#             self.traverse(root.right, target, right_node)

#     def distanceK(self, root, target, K):
#         """
#         :type root: TreeNode
#         :type target: TreeNode
#         :type K: int
#         :rtype: List[TreeNode]
#         """
#         node = AdjNode(root)
#         self.traverse(root, target, node)

#         res = []
#         queue = [self.tar_node]
#         self.tar_node.visited = 1
#         if K == 0:
#             res = [self.tar_node.ptr.val]

#         while queue != []:
#             cur = queue.pop(0)
#             for adj in cur.adj_list:
#                 if adj.visited == 0:
#                     adj.dist = cur.dist + 1
#                     adj.visited = 1
#                     queue.append(adj)

#                     if adj.dist == K:
#                         res.append(adj.ptr.val)

#         return res


a = set([1, 2])
b = list(a)
print(b)


















