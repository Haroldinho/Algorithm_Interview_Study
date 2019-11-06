import unittest

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def printTree_in_order_traversal(root:TreeNode):
    def _print_recursively(node: TreeNode):
        if node.left:
            _print_recursively(node.left)
        print(node.val, end=', ')
        if node.right:
            _print_recursively(node.right)
    _print_recursively(root)
    print()


class DeleteSolution:
    def findMaxNode(self, root: TreeNode) -> TreeNode:
        while root.right:
            root = root.right
        return root


    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root is None:
            return None
        elif root.val < key: #go to the right
            root.right = self.deleteNode(root.right, key)
        elif root.val > key: # go to the left
            root.left = self.deleteNode(root.left, key)
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
                node_to_be_replaced = self.findMaxNode(root.left)
                root.val = node_to_be_replaced.val
                root.left = self.deleteNode(root.left, root.val)
        return root




def test_simple():
    tree_root = TreeNode(1)
    tree_root.right = TreeNode(2)   
    printTree_in_order_traversal(tree_root)      
    delete_obj = DeleteSolution()
    print("Deletting node 1")
    root = delete_obj.deleteNode(tree_root, 1)
    printTree_in_order_traversal(root)

def test_complex():
    tree_root = TreeNode(12)
    tree_root.left = TreeNode(5)
    tree_root.right = TreeNode(15)
    tree_root.left.right = TreeNode(7)
    tree_root.left.left = TreeNode(3)
    tree_root.left.left.left = TreeNode(1)
    tree_root.left.right.right = TreeNode(9)
    tree_root.right.left = TreeNode(13)
    tree_root.right.right = TreeNode(17)
    tree_root.right.right.right = TreeNode(19)
    printTree_in_order_traversal(tree_root)

    print("Deleting node with value 7")
    delete_obj = DeleteSolution()
    root = delete_obj.deleteNode(tree_root, 7)
    printTree_in_order_traversal(root)

    print("Deleting node with value 15")
    root = delete_obj.deleteNode(tree_root, 15)
    printTree_in_order_traversal(root)

def test_three():
    tree_root = TreeNode(3)
    tree_root.left = TreeNode(1)
    tree_root.right = TreeNode(4)
    tree_root.left.right = TreeNode(2)

    printTree_in_order_traversal(tree_root)
    print("Deleting node with value 3")
    delete_obj = DeleteSolution()
    root = delete_obj.deleteNode(tree_root, 3)
    printTree_in_order_traversal(root)


def main():
    test_three()

if __name__ == '__main__': 
    # unittest.main() 
    main() 