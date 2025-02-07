# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def solve(head):

            if head is None or head.next is None:
                return head
            sec = head.next

            rest = solve(sec.next) if sec.next else None

            head.next = rest
            sec.next = head
            head = sec
            return head
        return solve(head)
        
        