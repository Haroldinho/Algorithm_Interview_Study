"""
NOT MY SOLUTION: USED FOR LEARNING
    https://leetcode.com/submissions/detail/278865986/
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        
        slow, fast = head, head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow and fast and slow == fast:
                slow = head
                while fast != slow:
                    slow = slow.next
                    fast = fast.next
                
                return slow
                    
        return None