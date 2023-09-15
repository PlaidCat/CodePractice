# 
# https://leetcode.com/problems/valid-anagram
#
# Solve Time:   8:04 
# Run Time:     49ms (84.99%)
# Memory:     16.9MB (36.28%)
# This is another example of me trying to do things what I think is a python
# like way and possibly missing the mark.  Run time is pretty good though.

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        chars = {}
        for char in s[0::1]:
            if char in chars:
                chars[char] += 1
            else:
                chars[char] = 1
        for char in t[0::1]:
            if char in chars:
                chars[char] -= 1
            else:
                return False
        
        for k,v in chars.items():
            if v != 0:
                return False
        return True