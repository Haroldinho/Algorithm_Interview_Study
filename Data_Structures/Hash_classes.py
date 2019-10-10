#!/usr/bin/python3
"""
            LeetCode HashSets and HashMaps Implementations
Goal: Learn how to implement hash sets and hash maps
Start with simple functions
As a reminder: two considerations exists for hash sets and hash maps
    1) A hash function that creates a uniform distribution of keys. (As uniform as possible)
    2) A process to handle name/key collision
https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/
"""

class MyHashSet:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.MAX_SIZE = 10000
        self.key_list = [[] for k in range(self.MAX_SIZE)]
    
    def contains(self, key:int) -> bool:
        """
            Returns true if set contains the specified
        key
        """
        does_contain = False
        key_idx = self.get_key_hash(key)
        if key in self.key_list[key_idx]:
            does_contain = True
        return does_contain


    def add(self, key:int)->None:
        if not self.contains(key):
            key_idx= self.get_key_hash(key)
            self.key_list[key_idx].append(key)

    def remove(self, key:int) -> None:
        if self.contains(key):
            key_idx = self.get_key_hash(key)
            for k in self.key_list[key_idx]:
                if k==key:
                    self.key_list[key_idx].remove(key)
                    return
class MyHashMap:
"""
All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
TODO Use MyHashSet directly
"""
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.MAX_SIZE = 10000
        self.key_list = [[] for k in range(self.MAX_SIZE)]
        self.value_list = [[] for v in range(self.MAX_SIZE)]

    def get_key_hash(self, key: int) -> int:
        """
            Hash function for the Hash set
        """
        key_idx = key%self.MAX_SIZE
        return key_idx

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        key_idx= self.get_key_hash(key)
        if self.contains(key):# (k, v) already exists -> update
            for i in range(len(self.key_list[key_idx])):
                if self.key_list[key_idx][i] == key:
                    self.value_list[key_idx][i] = value
        else:
            self.key_list[key_idx].append(key)
            self.value_list[key_idx].append(value)
        
    def contains(self, key:int) -> bool:
        """
            Returns true if set contains the specified
        key
        """
        does_contain = False
        key_idx = self.get_key_hash(key)
        if key in self.key_list[key_idx]:
            does_contain = True
        return does_contain

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        if self.contains(key):
            key_idx = self.get_key_hash(key)
            for idx in range(len(self.key_list[key_idx])):
                if self.key_list[key_idx][idx] == key:
                    return self.value_list[key_idx][idx]
        else:
            return -1
        

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        if self.contains(key):
            key_idx = self.get_key_hash(key)
            val = self.get(key)
            self.value_list[key_idx].remove(val)
            self.key_list[key_idx].remove(key)

        
def main():
#     obj = MyHashSet()
#     obj.add(1)
#     obj.add(2)
#     print("After adding 1 and 2 does obj contain 1? {}".format(obj.contains(1)))
#     print(obj.key_list[:10])
#     obj.add(3)
#     print("After adding 3  does obj contain 3? {}".format(obj.contains(3)))
#     print(obj.key_list[:10])
#     obj.remove(2)
#     print("After removing 2 does obj contain 2? {}".format(obj.contains(2)))
    obj = MyHashMap()
    hashMap.put(1, 1)
    hashMap.put(2, 2)
    print("Got value at 1 {}(1)".format(hashMap.get(1)))
    print("Got value at 3 {}(-1) since it's not there".format(hashMap.get(3)))
    hashMap.put(2, 1)
    hashMap.get(2)            
    hashMap.remove(2)
    hashMap.get(2)

if __name__ == "__main__":
    main()
