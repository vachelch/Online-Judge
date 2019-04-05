# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        h_A = headA
        h_B = headB
        la = 0
        lb = 0
        while h_A:
            la += 1
            h_A = h_A.next

        while h_B:
            lb += 1
            h_B = h_B.next

        if la > lb:
            for i in range(la - lb):
                headA = headA.next

        elif la < lb:
            for i in range(lb - la):
                headB = headB.next

        while headA:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next

        return None






















