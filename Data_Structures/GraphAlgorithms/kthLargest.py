import heapq
import unittest

class KthLargest:

    def __init__(self, k: int, nums):
        left_array = nums[:-k]
        self._heap = nums[-k:]
        heapq.heapify(self._heap)
        print("Initial: ", nums)
        if nums:
            for num in left_array:
                self.add(num)
        print("After adding all elements: ", self._heap)
        self._capacity = k

    def add(self, val):
        if len(self._heap) == 0:
            self._heap.append(val)
            return val
        current_kth_val = heapq.heappop(self._heap) # return smallest item from the heap
        if val > current_kth_val:
            return_val = heapq.heappushpop(self._heap, val)
            heapq.heappush(self._heap, return_val)
        else:
            heapq.heappush(self._heap, current_kth_val)
            return_val = current_kth_val
        return return_val
    
class TestInput1(unittest.TestCase):
    """
    Test if we obtain the correct output
    """
    def setUp(self):
        my_array = [4, 5, 8, 2]
        self._capacity =  3
        self.kthlargest_obj = KthLargest(self._capacity, my_array)

    def test_length(self):
        self.assertEqual(len(self.kthlargest_obj._heap), self._capacity)

    def test1(self):
        self.assertEqual(self.kthlargest_obj.add(3), 4)
        self.assertEqual(self.kthlargest_obj.add(5), 5)
        self.assertEqual(self.kthlargest_obj.add(10), 5)
        self.assertEqual(self.kthlargest_obj.add(9), 8)
        self.assertEqual(self.kthlargest_obj.add(4), 8)

class TestInput2(unittest.TestCase):
    """
    Test if we obtain the correct output
    """
    def setUp(self):
        self._my_array = []
        self._capacity =  1
        self.kthlargest_obj = KthLargest(self._capacity, self._my_array)

    def test_length(self):
        self.assertEqual(len(self.kthlargest_obj._heap), min(self._capacity,len(self._my_array)))

    def test1(self):
        self.assertEqual(self.kthlargest_obj.add(-3), -3)
        self.assertEqual(self.kthlargest_obj.add(-2), -2)
        self.assertEqual(self.kthlargest_obj.add(-4), -2)
        self.assertEqual(self.kthlargest_obj.add(0), 0)
        self.assertEqual(self.kthlargest_obj.add(4), 4)

if __name__ == "__main__":
    unittest.main()

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)