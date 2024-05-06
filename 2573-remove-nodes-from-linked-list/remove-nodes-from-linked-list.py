# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack = []
        temp = head
        while temp:
            current_value = temp.val
            while stack and current_value > stack[-1]:
                stack.pop()
            stack.append(current_value)
            temp = temp.next
        
        head = ListNode(stack[0])
        temp2 = head
        for i in range(1, len(stack)):
            temp2.next = ListNode(stack[i])
            temp2 = temp2.next
        return head

        