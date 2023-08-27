# 
# https://leetcode.com/problems/invert-binary-tree
#
# Solve Time:   1:45 ()
# Run Time:  25-46ms ( 99.96->41.80%) Python
# Memory:     16.4MB (32.28%)
#
# Just recreated my CPP version.
# Hoewever I was shocked on the peformance difference when
# I submitted my code.  If you run it a couple times in a
# row it will change the amount of time by 20+ms.  This could
# be a lot of reason just beyond the python interpreter being
# weird.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return root
        tmp = root.left
        root.left = root.right
        root.right = tmp
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root