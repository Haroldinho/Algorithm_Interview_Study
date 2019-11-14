"""
Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example,  The input [1, 2, 0] should give 3.
You can modify the array
"""


from typing import List
import unittest
import random


def return_first_missing_positive_num(nums: List) -> int:
    """
    This solution is O(nlog n) in time and O(1) in space
    """
    my_sorted_array = sorted(nums)
    # iterate thrugh array 
    current_num = 1
    for num in my_sorted_array:
        if num == current_num:
            current_num += 1
        elif num > current_num:
            break
    return current_num

class TestOne(unittest.TestCase):
    """
    The input [3, 4, -1, 1] should give 2.
    """
    def setUp(self):
        self._array = [3,4,-1,1]
        self._result = return_first_missing_positive_num(self._array)

    def test_value(self): 
        self.assertEqual(self._result, 2)


class TestTwo(unittest.TestCase):
    """
    The input [3, 4, -1, 1] should give 2.
    """
    def setUp(self):
        self._array = [1, 2, 0]
        self._result = return_first_missing_positive_num(self._array)

    def test_value(self): 
        self.assertEqual(self._result, 3)

def main():
    """
     Big test create an array remove an element and shuffle the array
    """
    n = 200
    rand_idx = random.randint(0,199)
    my_array = [i for i in range(n)]
    del my_array[rand_idx]

if __name__ == "__main__":
    unittest.main()