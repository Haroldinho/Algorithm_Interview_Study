"""
Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example,  The input [1, 2, 0] should give 3.
"""


from typing import List
import unittest


def return_first_missing_positive_num(nums: List) -> int:
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

if __name__ == "__main__":
    unittest.main()