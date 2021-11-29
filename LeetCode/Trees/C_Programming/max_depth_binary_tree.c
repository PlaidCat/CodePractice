/**
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/ 
 * 
 * Runtime: 4 ms
 * Memory Usage: 7.9 MB
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dive(struct TreeNode* root, int depth, int *max_depth){
  if (root == NULL)
    return;
  if (depth > *max_depth)
    *max_depth = depth;
  dive(root->left, depth+1, max_depth);
  dive(root->right, depth+1, max_depth);
}

int maxDepth(struct TreeNode* root){
  if (root == NULL)
    return 0;
  int max_depth = 1;
  dive(root->left, 2, &max_depth);
  dive(root->right, 2, &max_depth);
  return max_depth;
  
}