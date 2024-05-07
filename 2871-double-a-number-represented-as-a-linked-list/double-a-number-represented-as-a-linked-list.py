# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack = []
        temp = head
        while temp:
            stack.append(temp.val)
            temp = temp.next
        
        carry = 0
        for i in range(len(stack) - 1, -1, -1):
            k = stack[i]
            stack[i] = (2*k + carry) % 10
            carry = (2*k + carry) // 10
        
        if carry:
            ans = ListNode(carry)
            tmp = ans
            for val in stack:
                tmp.next = ListNode(val)
                tmp = tmp.next
        else:
            ans = ListNode(stack[0])
            tmp = ans
            for i in range(1, len(stack)):
                tmp.next = ListNode(stack[i])
                tmp = tmp.next
        
        return ans


