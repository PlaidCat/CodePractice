# 
# https://leetcode.com/problems/valid-parentheses
#
# Solve Time:   ??? (got interrupted by cats)
# Run Time:    47ms ( 7.93%)
# Memory:    17.1MB (61.73%)
#
# Just recreated my CPP version with some stl function name changes.
#

class Solution:
    def isPalindrome(self, s: str) -> bool:
        strSize = len(s)
        if strSize < 2:
            return True
        start = 0 
        end = strSize - 1

        while start < end:
            if not s[start].isalnum():
                start += 1
                continue
            if not s[end].isalnum():
                end -= 1
                continue
            if s[start].lower() != s[end].lower():
                return False
            start += 1
            end -= 1

        return True