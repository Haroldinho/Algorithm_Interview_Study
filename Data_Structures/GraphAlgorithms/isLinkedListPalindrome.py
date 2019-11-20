"""
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

"""
import unittest
from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def print_linked_list(self, head:ListNode, length=None):
        node = head
        count = 0
        while node:
            if length:
                if count >=length:
                    break
            print(node.val,end=", ")
            node = node.next
        print("")

    def get_num_nodes(self, head:ListNode) -> int:
        node = head
        num_nodes = 0
        while node:
            node = node.next
            num_nodes += 1
        return num_nodes
    
    def get_head_to_second_half(self, head:ListNode, len_half: int) -> ListNode:
        node = head
        count = 0 
        while node and count < len_half:
            node = node.next
            count += 1
        return node
    
    def reverse_list(self, head:ListNode) -> ListNode:
        node = head
        while node.next:
            temp = node.next
            node.next = node.next.next
            temp.next = head
            head = temp
        return head
        
        
    def isPalindrome(self, head: ListNode) -> bool:
        # Jus reverse the list and compare the reversed list to the original
        if not head or not head.next:
            return True
        num_nodes = self.get_num_nodes(head)
        print("Linked list has size: ", num_nodes)
        self.print_linked_list(head)
        # get the floor of half the number of noes
        len_half = int(num_nodes/2)
        self.print_linked_list(head, len_half)

        head_to_second_half = self.get_head_to_second_half(head, len_half)
        self.print_linked_list(head_to_second_half)
        head_to_second_half = self.reverse_list(head_to_second_half)
        self.print_linked_list(head_to_second_half)
        i = 0
        node_left = head
        node_right = head_to_second_half
        return_val = True
        while node_right and i < len_half:
            if node_left.val != node_right.val:
                return_val = False
                break
            node_right = node_right.next
            node_left  = node_left.next
            i += 1
        return return_val

def main():
    head = ListNode(1)
    head.next = ListNode(2)
    sol = Solution()
    print("It is: ", sol.isPalindrome(head))
        
class TestInput0(unittest.TestCase):
    """
    Test if we obtain the correct output
    """
    def setUp(self):
        self.head = ListNode(1) 
        self.head.next = ListNode(2)
        self.sol = Solution()

    def test0(self):
        self.assertFalse(self.sol.isPalindrome(self.head))

class TestInput1(unittest.TestCase):
    """
    Test if we obtain the correct output
    """
    def setUp(self):
        self.head = ListNode(1) 
        self.head.next = ListNode(2)
        self.head.next.next = ListNode(2)
        self.head.next.next.next = ListNode(1)
        self.sol = Solution()

    def test0(self):
        self.assertTrue(self.sol.isPalindrome(self.head))

class TestInput1(unittest.TestCase):
    """
    Test if we obtain the correct output
    """
    def setUp(self):
        self.head = ListNode(1) 
        self.head.next = ListNode(2)
        self.head.next = 
        self.head.next.next = ListNode(2)
        self.head.next.next.next = ListNode(1)
        self.sol = Solution()

    def test0(self):
        self.assertTrue(self.sol.isPalindrome(self.head))


if __name__ == "__main__":
    unittest.main()
        
        