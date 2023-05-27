#
# https://leetcode.com/problems/two-sum
# 
# This was super fast to write so I should start setting up a time for completion.
#
# Runtime 3860ms (18.84%)
# Memory  17.2MB (32.79%)
#
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if (nums[i] + nums[j]) == target:
                    return [i, j]