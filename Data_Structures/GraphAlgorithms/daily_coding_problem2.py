#!/usr/bin/python3
import unittest

"""
Given an array of integers, 
return a new array such that each element at index i of the new array 
is the product of all the numbers in the original array except the one at i.

Solution 1: Obtain the product of the entire list, then iterate through the list and divide by each number to return the final list.
"""



class Solution1:
    def __init__(self, an_array):
        product = 1
        for elt in an_array:
            product *= elt
        self._product = product
        self._array = an_array
        
    def return_new_array(self):
        my_array = []
        for elt in self._array:
            my_array.append(self._product/elt)
        return my_array


class TestArray1(unittest.TestCase):
    """
    Test if we obtain the correct output
    """
    def setUp(self):
        my_array = [3, 2 ,1]
        self.result_array = [2,3,6]
        obj1 = Solution1(my_array)
        self.obtained_array = obj1.return_new_array() 

    def test_final_array_method1(self):
        self.assertListEqual(self.obtained_array, self.result_array)

class TestArray2(unittest.TestCase):
    """
    Test if we obtain the correct output
    """
    def setUp(self):
        my_array = [1, 2, 3, 4, 5]
        self.result_array = [120, 60, 40, 30, 24]
        obj1 = Solution1(my_array)
        self.obtained_array = obj1.return_new_array() 

    def test_final_array_method1(self):
        self.assertListEqual(self.obtained_array, self.result_array)


if __name__ == "__main__":
    unittest.main()