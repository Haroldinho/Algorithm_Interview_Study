# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        slow_count = 0
        fast_count = 0
        if head is None:
            return None
        if head.next is None:
            return None
        slow_node = head
        fast_node = head
        while fast_node.next:
            fast_count += 1
            fast_node = fast_node.next
            if fast_count > slow_count + n :
                slow_node = slow_node.next
                slow_count += 1
 
            #print(fast_count, slow_count)
        if slow_node == head:
            if fast_count== n + slow_count:
                slow_node.next = slow_node.next.next
            else:#fast_count > n + slow_count, we should remove the head
                head = slow_node.next
        elif slow_node.next:
            slow_node.next = slow_node.next.next
        else:
            slow_node.next = None
        return head