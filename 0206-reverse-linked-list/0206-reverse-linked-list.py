# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        if(head is None or head.next is None):
            return head
        
        prev=None
        curr=head
        Next=head.next

        while Next:
            curr.next=prev
            prev=curr
            curr=Next
            Next=Next.next

        curr.next=prev
        return curr
        
        