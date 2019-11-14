class MyNode:
    def __init__(self, val):
        self._val = val
        self.next = None
    
class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._head = MyNode(-1)
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        idx = 0
        
        node = self._head.next
        if not node:
            return -1
        for i in range(index):
            if node.next:
                node = node.next
            else:
                return -1
        return node._val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        new_node = MyNode(val)
        new_node.next = self._head.next
        self._head.next = new_node

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        root = self._head
        while root.next:
            root = root.next
        root.next = MyNode(val)

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        root = self._head
        idx = 0
        while idx < index and root.next:
            root = root.next
            idx += 1
        if idx == index:
            my_node=  MyNode(val)
            my_node.next = root.next
            root.next = my_node

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        root = self._head
        idx = 0
        while idx < index and root.next:
            root = root.next
            idx += 1
        if idx ==index:
            if root.next:# bypass this node
                root.next = root.next.next


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)