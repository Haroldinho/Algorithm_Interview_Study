class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right  = None


"""
Inorder tree traversal example
"""


class Solution:
    def isValidBTS(self, root_node:TreeNode) -> bool:

        MAX_VAL = float("inf")
        MIN_VAL = float("-inf")

        def _is_valid(node: TreeNode, lower_bound:float, upper_bound:float) -> bool:
            if node is None:
                return True
            return (lower_bound < node.val < upper_bound) and _is_valid(node.left, lower_bound, node.val) \
                    and _is_valid(node.right, node.val, upper_bound)
        return _is_valid(root_node, MIN_VAL, MAX_VAL)


def simple_main():
    """
    Run a few examples and print whether it's true or not
    :return: Nothing
    """
    simple_tree_root = TreeNode(8)
    simple_tree_root.left = TreeNode(7)
    simple_tree_root.right = TreeNode(9)
    sol = Solution()
    print("The test should be ", sol.isValidBTS(simple_tree_root))


def more_complicated_main():
    """
    Should really be a unit test
    :return:
    """
    tree_root = TreeNode(10)
    tree_root.left = TreeNode(8)
    tree_root.right = TreeNode(15)
    tree_root.left.left = TreeNode(7)
    tree_root.left.right = TreeNode(9)
    tree_root.left.left.left = TreeNode(4)
    tree_root.right.left = TreeNode(5)
    tree_root.right.right = TreeNode(16)
    sol = Solution()
    print("The test should be ", sol.isValidBTS(tree_root))


if __name__ == "__main__":
    # simple_main()
    more_complicated_main()

