from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #print("Initial ", nums)
        i = 1
        n = len(nums)
        current_max = float("-inf")
        while i< len(nums):
            #1 . find next repeated value
            current_max = max(current_max, nums[i-1])
            if nums[i]<= nums[i-1]:
                # 2. find next value greater than current
                j = i+1
                while j < len(nums) and nums[j]<= current_max:
                    j += 1
                if j==len(nums): # no value found
                    return i
                else:
                    # Swap the two
                    nums[i] = nums[j]
                    n -= 1
            i += 1
            #print(nums, ' ', i, ' ', current_max)
        return n
            
        