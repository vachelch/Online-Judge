# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head == None: return head
        top = ListNode(-1)
        top.next = head
        head = top

        while head and head.next:
            if head.next.val == val:
                head.next = head.next.next
                continue
            head = head.next 

        return top.next












