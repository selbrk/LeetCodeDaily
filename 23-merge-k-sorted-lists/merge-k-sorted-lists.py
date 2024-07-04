# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeTwoLists(list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()
            tail = dummy
            while list1 and list2:
                if list1.val < list2.val:
                    tail.next = list1
                    list1 = list1.next
                else:
                    tail.next = list2
                    list2 = list2.next
                tail = tail.next
            if list1:
                tail.next = list1
            elif list2:
                tail.next = list2
            return dummy.next
        if len(lists) == 0:
            return None
        
        ans = lists[0]
        for i in range(1, len(lists)):
            ans = mergeTwoLists(ans, lists[i])
        return ans

        