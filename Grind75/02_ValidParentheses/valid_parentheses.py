# 
# https://leetcode.com/problems/valid-parentheses
#
# Solve Time: 8:40
# Run Time:     54ms ( 7.93%)
# Memory:     16.5MB (17.60%)
#
# Both this one and TwoSum were really slow and space inefficent use of space even for the other Python submissions.
# This is likely an issue on my side of python-ese
#
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        stack_size = 0
        for i in s:
            print(i)
            if i is '(' or i is '{' or i is '[':
                stack.append(i)
                stack_size+=1
            elif stack_size > 0:
                if (i == ')') and (stack[stack_size - 1] == '('):
                    stack.pop() 
                elif (i == '}') and (stack[stack_size - 1] == '{'):
                    stack.pop()
                elif (i == ']') and (stack[stack_size - 1] == '['):
                    stack.pop()
                else:
                    return False
                stack_size-=1
            else:
                return False
        if stack_size != 0:
            return False
        return True