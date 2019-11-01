# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


from collections import deque
class BSTIterator:
    """
    We create an explicit Stack to maintain the state of the iterator after each successful call
    """

    def __init__(self, root: TreeNode):
        self._my_stack = deque()
        if root:
            self._my_stack.append(root)
        self._visited = set()
        # visited=0 if node has been seen, visited = 1 if left branch has been exhausted, visited=2 if right branch has been exhausted

    def build_stack(self):
        node = self._my_stack.pop()
        # have we seen the root node before, in this case go to the left
        if node.val not in self._visited:
            while node.left and node.left.val not in self._visited:
                self._my_stack.append(node)
                node = node.left
            self._my_stack.append(node)
        
    def next(self) -> int:
        """
        @return the next smallest number
        """
        node = self._my_stack.pop()
        # have we seen the root node before, in this case go to the left
        while node.left and node.left.val not in self._visited:
            self._my_stack.append(node)
            node = node.left
        if node.right:
            self._my_stack.append(node.right)
        self._visited.add(node.val)
        return node.val

            
                  
        
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self._my_stack) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()

