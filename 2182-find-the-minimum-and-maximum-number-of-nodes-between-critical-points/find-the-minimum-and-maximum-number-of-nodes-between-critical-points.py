# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        def critical(current_node, previous_node):
            if not (previous_node and current_node.next):
                return False

            diff1, diff2 = current_node.val - previous_node.val, current_node.val - current_node.next.val
            return True if diff1 * diff2 > 0 else False
        

        previous_node, current_node = None, head
        first_seen, last_seen = -1, -1
        min_distance = float('inf')
        itr = 0
        while current_node:
            if not critical(current_node, previous_node):
                previous_node = current_node
                current_node = current_node.next
                itr += 1
                continue
            print("here")
            if first_seen == -1:
                first_seen = itr
            if last_seen != -1:
                dist = itr - last_seen
                min_distance = min(min_distance, dist)
            last_seen = itr
            
            previous_node = current_node
            current_node = current_node.next

            itr += 1
        
        max_distance = last_seen - first_seen
        return [min_distance, max_distance] if max_distance else [-1,-1]

            


        