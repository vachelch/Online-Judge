# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
import queue

class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if head ==None or head.next == None: return True

        f_ptr = head
        s_ptr = head
        stack = queue.LifoQueue()
        while f_ptr != None and f_ptr.next != None:
            stack.put(s_ptr)
            f_ptr = f_ptr.next.next
            s_ptr = s_ptr.next
        
        if f_ptr != None:
            s_ptr = s_ptr.next

        while not stack.empty():
            if stack.get().val == s_ptr.val:
                s_ptr = s_ptr.next
            else:
                return False

        return True

x1 = ListNode(1)
x2 = ListNode(2)
x3 = ListNode(1)

x1.next = x2
x2.next = x3

s = Solution()
print(s.isPalindrome(x1))















