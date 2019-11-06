from collections import deque
class TreeNode:
    def __init__(self,val):
        self.val = val
        self.neighbors = []

def bfs(root: TreeNode):
    visited = []
    my_queue = deque()
    my_queue.append(root)
    while my_queue:
        node = my_queue.popleft()
        for neighbor in  node.neighbors:
            if neighbor not in visited:
                my_queue.append(neighbor)
                visited.append(neighbor)




def dfs(root: TreeNode):
    visited = []
    my_stack = deque()
    my_stack.append(root)
    while my_stack:
        node = my_stack.pop()
        for neighbor in node.neighbors:
            if neighbor not in visited:
                my_stack.append(neighbor)
                visited.append(neighbor)


# Recusive Stack
def r_dfs(root:TreeNode):
    visited = []

    def _rdfs(node):
        if node is None:
            return
        for neighbor in node.neighbors:
            if neighbor not in visited:
                _rdfs(neighbor)
                visited.append(neighbor)
    return _rdfs(root)
