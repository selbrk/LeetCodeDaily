class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        class Node:
            def __init__(self, val=0, next=None, prev=None):
                self.val = val
                self.next = next
                self.prev = prev
            def remove(self):
                self.prev.next = self.next
                self.next.prev = self.prev
        
        head = Node(1)
        current = head
        for i in range(2, n+1):
            current.next = Node(i, next=None, prev=current)
            current = current.next
        
        current.next = head
        head.prev = current

        current = head
        while current.next != current:
            i = 1
            while i < k:
                current = current.next
                i += 1
            to_remove = current
            current = current.next
            to_remove.remove()
        
        return current.val




        

        
