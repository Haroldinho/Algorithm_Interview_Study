"""
Daily Coding Problem #3 [Medium]

Given the root to a binary tree, 
implement serialize(root), which serializes the tree into a string, 
and deserialize(s), which deserializes the string back into the tree.
"""

import unittest
from collections import deque

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def serialize(root:Node):
    """
    Use Breadth-First Search to serialize the tree
    """
    my_queue = deque()
    my_queue.append(root)
    return_string = ""
    if my_queue:
        return_string = "{}".format(root.val)
    while my_queue:
        node = my_queue.popleft()
        if node.left:
            return_string += ", {next_node}".format(next_node=node.left.val)
            my_queue.append(node.left)
        if node.right:
            return_string += ", {next_node}".format(next_node=node.right.val)
            my_queue.append(node.right) 
    print(return_string)
    return return_string


def deserialize(tree_str: str) -> Node:
    """
        Reconstruct a tree from the serialized string
        and return the root node pointer

    """
    list_values = tree_str.replace(' ','').split(',')
    num_nodes = len(list_values)
    # Enqueue all the values
    print(list_values)
    root = Node(list_values[0])
    my_queue = deque()
    my_queue.append((root,0))
    while my_queue:
        new_node, idx = my_queue.popleft()
        print(new_node.val, idx)
        left_index = 2*idx + 1
        right_index = 2*idx + 2
        if left_index < num_nodes:
            new_node.left = Node(list_values[left_index])
            my_queue.append((new_node.left, left_index))
            if right_index < num_nodes:
                new_node.right = Node(list_values[right_index])
                my_queue.append((new_node.right, right_index))
    return root


class TestOne(unittest.TestCase):
    """
    Test if we what is deserialized is the same as what has been serialized
    """
    def setUp(self):
        self._node = Node('root', Node('left', Node('left.left')), Node('right'))
        self._result = deserialize(serialize(self._node))

    def test_left(self): 
        self.assertEqual(self._result.left.val, 'left')

    def test_left_left(self): 
        self.assertEqual(self._result.left.left.val, 'left.left')


if __name__ == "__main__":
    unittest.main()