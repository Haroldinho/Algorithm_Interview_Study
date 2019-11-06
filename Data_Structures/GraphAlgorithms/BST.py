"""
Implementation of a Binary Search Tree Class
"""

class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.left = None
        self.right = None:


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

    def search(self, val:int, node=self._root) -> TreeNode:
        if node is None:
            return node
        if val < node.val:
            return self.search(val, node.left)
        elif val > node.val:
            return self.search(val, node.right)
        else:
            return node

    def find_min(self, node=self._root: TreeNode) -> TreeNode:
        while node.left:
            node = node.left
        return node

    def find_max(self, node=self._root:TreeNode) -> TreeNode:
        while node.right:
            node = node.right
        return node

    def output_in_sorted_order(self) -> List[int]:
        def _append_to_array(my_array, node):
            if node.left:
                _append_to_array(node.left)
            my_array += [node.val]
            if node.right:
                _append_to_array(node.right)
        return _append_to_array([],self._root)
    
    