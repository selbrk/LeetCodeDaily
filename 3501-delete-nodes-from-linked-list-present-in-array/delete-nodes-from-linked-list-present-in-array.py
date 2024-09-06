# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        nums = set(nums)
        curr = head
        l = []
        while curr:
            if curr.val not in nums:
                l.append(curr.val)
            curr = curr.next
        
        if not l:
            return []
        
        head = ListNode(l[0])

        prv = head

        for i in range(1, len(l)):
            prv.next = ListNode(l[i])
            prv = prv.next
        
        return head

        
        return head
        