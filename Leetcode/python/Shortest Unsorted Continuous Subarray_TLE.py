#O(n^2)

def swap(a, i, j):
    tmp = a[i]
    a[i] = a[j]
    a[j] = tmp

def insert(nums, i):
    while i>0 and nums[i] < nums[i-1]:
        swap(nums, i, i-1)
        i -= 1
    return i

class Solution:
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        start = end = 10000
        if l == 1: return 0

        for i in range(1, l):
            if nums[i] < nums[i-1]:
                end = i
                index = insert(nums, i)
                start = min(start, index)
        if start == end:
            return 0
        else:
            return end - start + 1















