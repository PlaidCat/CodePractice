/*
 * https://leetcode.com/problems/invert-binary-tree/
 *  
 * Code:   1:14
 *  CPU:    0ms (100.0%)
 *  MEM: 9.77MB (19.69%)
 * Similar compiler optimization issues as C
 * Using the C solution I did 33.40 and 19.69 %
 * just like in the C version.
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL){
            return root;
        }
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};