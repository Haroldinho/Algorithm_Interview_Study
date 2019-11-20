class MyNode:
    def __init__(self, val):
        self._val = val
        self.next = None
        self.prev = None
    
class MyDoublyLinkedList:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._head = MyNode(-1)
        self._tail = MyNode(-1)
        self._head.next = self._tail
        self._tail.prev = self._head
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        node = self._head.next
        idx = 0
        if node == self._tail:
            return -1
        while  idx < index:
            if node == self._tail:
                return -1
            node = node.next
            idx += 1
        return node._val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the           first node of the linked list.
        """
        new_node = MyNode(val)
        new_node.next = self._head.next
        new_node.prev = self._head
        self._head.next.prev = new_node
        self._head.next = new_node

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        new_node = MyNode(val)
        new_node.next = self._tail
        new_node.prev = self._tail.prev
        self._tail.prev.next = new_node
        self._tail.prev = new_node

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. 
        If index equals to the length of linked list, the node will be appended to the end of linked list. 
        If index is greater than the length, the node will not be inserted.
        """
        if index >=0:
            root = self._head.next
            idx = 0
            while idx < index and root != self._tail:
                root = root.next
                idx += 1
            if idx< index:# it means that the root is already at the tail, but not yet at the correct index
                return 
            my_node = MyNode(val)
            my_node.next = root
            my_node.prev = root.prev
            root.prev.next = my_node
            root.prev = my_node
                
        else:
            node= self._tail.prev
            if node== self._head:
                self.addAtHead(val)
            count = -index
            idx = 1
            while idx < count and node != self._head:
                node = node.prev
                idx += 1
            # add the new node after node
            my_node = MyNode(val)
            my_node.prev = node
            my_node.next = node.next
            node.next.prev = my_node
            node.next = my_node


    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if self._head.next == self._tail:
            # nothing to do
            return 
        if index>=0:
            root = self._head.next
            idx = 0
            while idx < index:
                if root.next == self._tail:
                    return 
                root = root.next
                idx += 1
            root.next.prev = root.prev
            root.prev.next = root.next
        else:
            root = self._tail.prev
            idx = 1
            index = - index
            while idx< index and root.prev != self._head:
                root = root.prev
                idx += 1
            root.prev.next = root.next
            root.next.prev = root.prev

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)