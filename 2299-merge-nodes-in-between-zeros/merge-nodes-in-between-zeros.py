# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head.next
        sum_ = 0

        current = None
        ans = None
        while temp:
            if temp.val == 0:
                if ans:
                    current.next = ListNode(sum_)
                    current = current.next
                else:
                    ans = ListNode(sum_)
                    current = ans
                sum_ = 0
            else:
                sum_ += temp.val
            temp = temp.next
        
        return ans



        