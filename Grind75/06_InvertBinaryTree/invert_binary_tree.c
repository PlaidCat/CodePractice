/*
 * https://leetcode.com/problems/invert-binary-tree/
 *  
 * Code:   2:19
 *  CPU:    3ms (45.85%)
 *  MEM:  5.8MB (32.56%)
 * This sounded way more complex when initially reading.  But a
 * 2m 19s solve time is pretty nice to me.  However I'm not really
 * sure why my solution is 3ms and the optimal is 0ms.  The only
 * think I can thnk of is that the 0ms might benefit from compiler
 * optimization even though they are doing the same thing but
 * because they're explicit actions of the left right swap then
 * the recursive calls it might do clever things with registers.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL){
        return root;
    }
    struct TreeNode *tmp;
    tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}

//0ms optimal for reference
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return root;
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}