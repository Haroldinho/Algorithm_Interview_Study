"""
Given a directed acyclic graph, assign an order of traversals to all nodes using DFS
"""
class TreeNode:
    def __init__(self,val):
        self.val = val
        self.neighbors = []
        self.label = None


def topological_sort(root, N):
    """

    :param root:  Starting node of the graph
    :param N: Number of nodes in the graph
    :return: Nada
    """
    current_label = N
    visited = []

    def dfs(node, current_label=N):
        visited.append(node)
        for neighbor in node.neighbors:
            if neighbor not in visited:
                current_label = dfs(neighbor, current_label)
        node.label = current_label
        current_label -= 1
        return current_label
    return dfs(root)
