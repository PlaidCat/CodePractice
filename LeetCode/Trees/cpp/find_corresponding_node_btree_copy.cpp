/*
 * https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 * 
 * Daily Challenge (Medium)
 * 
 * Runtime: 604 ms (68.91% Better)
 * Memory Usage: 163.9 MB (58.30% Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 *
 * This was a complete joke of a medium, given the constraints of all nodes are unique values you don't even need the original tree.
 * 
 * I thought there might have been a gotcha but nope, there are harder easy's on this site.
 *  
 * /

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      if (cloned == NULL)
        return NULL;
      if (target->val == cloned->val)
        return cloned;
      
      TreeNode *ret;
      ret = getTargetCopy(original, cloned->left, target);
      if (ret != NULL)
        return ret;
      ret = getTargetCopy(original, cloned->right, target);
      return ret;
    }
};