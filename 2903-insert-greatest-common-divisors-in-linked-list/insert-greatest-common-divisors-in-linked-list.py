# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def gcd(a,b):
            return a if b == 0 else gcd(b, a % b)
        temp = head
        while temp.next:
            val1 = temp.val
            val2 = temp.next.val
            gcd_ = gcd(val1,val2)
            node = ListNode(gcd_)
            temp2 = temp.next
            temp.next = node
            node.next = temp2
            temp = temp2
        return head


        