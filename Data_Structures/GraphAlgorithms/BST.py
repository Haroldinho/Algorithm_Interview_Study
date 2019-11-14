"""
Implementation of a Binary Search Tree Class
"""
from typing import List
class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.left = None
        self.right = None


class BinarySearchTree:
    """
    Implement the following methods:
        - Search
        - Select
        - MIN/MAX
        - PRED/Succ
        - Output IN Sorted order as a List
        - Insert
        - Delete
    """
    def __init__(self, root: TreeNode):
            self._root = root

    def search(self, val:int, node) -> TreeNode:
        if node is None:
            return node
        if val < node.val:
            return self.search(val, node.left)
        elif val > node.val:
            return self.search(val, node.right)
        else:
            return node

    def find_min(self, node) -> TreeNode:
        while node.left:
            node = node.left
        return node

    def find_max(self, node) -> TreeNode:
        while node.right:
            node = node.right
        return node

    def output_in_sorted_order(self):
        """
        in-order traversal of the tree
        """
        def _append_to_array(my_array, node):
            if node.left:
                _append_to_array(my_array, node.left)
            my_array += [node.val]
            if node.right:
                _append_to_array(my_array, node.right)
        return _append_to_array([],self._root)
    
    
    def delete_node(self, key: int, root) -> TreeNode:
        """
         Routine to delete a node, if the node has two children, swap with the glb
        """
        if root is None:
            return None
        elif root.val < key: #go to the right
            root.right = self.delete_node(root.right, key)
        elif root.val > key: # go to the left
            root.left = self.delete_node(root.left, key)
        else: # the current root is the one that needs to be deleted
            # Case 1: No children
            if root.right is None and root.left is None:
                # just delete that node
                root = None
            elif root.right is None: # root.left is None
                # swap with the left node
                root.val = root.left.val
                root = root.left
            elif root.left is None:
                root = root.right
            else: # neither is None
                node_to_be_replaced = self.find_max(root.left)
                root.val = node_to_be_replaced.val
                root.left = self.delete_node(root.left, root.val)
        return root

    def insert_node(self, root_node:TreeNode, key:int) -> TreeNode:
        if root_node is None:
            return TreeNode(key)
        if key < root_node.val:
            root_node.left = self.insert_node(root_node.left, key)
        else:
            root_node.right = self.insert_node(root_node.right, key)
        return root_node

    def rebalanceTree(self):
        # Create an array using inorder tree-traversal 
        # Transform the tree into a self_balance_tree starting at the middle
        sorted_array = self.output_in_sorted_order()
        def self_balance_tree(array: List[int]) -> TreeNode:
            if len(array)==0:
                return None
            mid_idx = int(len(array)/2)
            root = TreeNode(array[mid_idx])
            root.left = self_balance_tree(array[:mid_idx])
            root.right = self_balance_tree(array[mid_idx+1:])
            return root
        return self_balance_tree(sorted_array)
