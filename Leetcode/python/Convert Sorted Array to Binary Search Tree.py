# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def build_tree(nums, start, end):
            if start > end: return None

            pivot = (start + end)//2
            root = TreeNode(nums[pivot])
            root.left = build_tree(nums, start, pivot -1)
            root.right = build_tree(nums, pivot +1, end)

            return root

        return build_tree(nums, 0, len(nums) - 1)