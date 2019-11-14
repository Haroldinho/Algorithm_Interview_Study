"""
Daily Coding problem 7: Decoding the alphabet
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
"""
import unittest

code_dict = {i:chr(96+i) for i in range(1,27)}

def compute_number_of_codes(code_string):
    if len(code_string) == 0:
        return 1
    if len (code_string) == 1:
        if int(code_string) in code_dict:
            return 1
        else:
            return 0
    val_1 = compute_number_of_codes(code_string[1:])
    val_2 = 0
    if int(code_string[:2]) in code_dict:
        val_2 = compute_number_of_codes(code_string[2:])
    return  val_1  + val_2

    

class TestOne(unittest.TestCase):
    """
    Simple three letters test
    """

    def test_one(self): 
        """
        '111' -> 3
        """
        self.assertEqual(compute_number_of_codes('111'), 3)

    def test_two(self): 
        """
        '275' -> 1
        """
        self.assertEqual(compute_number_of_codes('275'), 1)

if __name__ == "__main__":
    unittest.main()



