class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self._order = k
        self._root = TreeNode(nums[0])
        for val in nums[1:]:
            self.add_node_to_tree(self._root, val)
            
    def add_node_to_tree(self, root:TreeNode, val):
        if root == None:
            root = TreeNode(val)
        elif val <= root.val:
            self.add_node_to_tree(root.left, val)
        elif val > root.val:
            self.add_node_to_tree(root.right, val)
            
        
    def add(self, val: int) -> int:
        self.add_node_to_tree(self._root, val)
        return self.return_k_val()
        
    def return_k_val(self):
        an_array = self.return_array()
        return an_array[self._order-1]
        
    def return_array(self):
        def _append_to_array(my_array, node):
            if node.left:
                _append_to_array(node.left)
            my_array += [node.val]
            if node.right:
                _append_to_array(node.right)
        return _append_to_array([],self._root)


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)