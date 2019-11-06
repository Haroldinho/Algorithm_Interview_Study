import heapq
import unittest

class KthLargest:

    def __init__(self, k: int, nums):
        left_array = nums[:-k]
        right_array = nums[k+1:]
        self._heap = heapq.heapify(right_array)
        for num in left_array:
            self.add(num)
        self._capacity = k

    def add(self, val):
        current_kth_val = heapq.heappop(self._heap) # return smallest item from the heap
        if val > current_kth_val:
            return_val = heapq.heappushpop(self._heap, val)
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
        k =  3
        self.kthlargest_obj = KthLargest(k, my_array)

    def test1(self):
        self.assertEqual(self.kthlargest_obj.add(3), 4)
        self.assertEqual(self.kthlargest_obj.add(5), 5)
        self.assertEqual(self.kthlargest_obj.add(10), 5)
        self.assertEqual(self.kthlargest_obj.add(9), 8)
        self.assertEqual(self.kthlargest_obj.add(4), 8)
if __name__ == "__main__":
    unittest.main()

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)