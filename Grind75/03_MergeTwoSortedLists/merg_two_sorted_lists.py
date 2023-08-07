# https://leetcode.com/problems/merge-two-sorted-lists/submissions/
# Exact same code as logic as the C variation but I wanted to see what would happen.
# I was a little worried Python would not behave correctly.
#  
# Code:  ~5:30
#  CPU:   20ms (76.6%)
#  MEM: 13.3MB (85.72%)
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if list1 is None:
            return list2
        if list2 is None:
            return list1

        if list1.val < list2.val:
            merged = list1
            list1 = list1.next
        else:
            merged = list2
            list2 = list2.next
        merged_head = merged

        while (list1 != None) and (list2 != None):
            if list1.val < list2.val:
                merged.next = list1
                merged = merged.next
                list1 = list1.next
            else:
                merged.next = list2
                merged = merged.next
                list2 = list2.next

        if list1 != None:
            merged.next = list1
        if list2 != None:
            merged.next = list2
        return merged_head