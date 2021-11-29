/**
 * Delete Node in a Linked List
 * Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
 * 
 * It is guaranteed that the node to be deleted is not a tail node in the list. 
 * 
 * https://leetcode.com/problems/delete-node-in-a-linked-list/
 * 
 * COMMENTS:
 * This was extremely weirdly worded, basically you're indirectly deletingh the "Given Node".
 * 
 * You're actually deleting the next node, by copying all of its details into the provided node 
 * (this is the hint about never a tail node because you'll have null pointer dereferences otherwise.)
 * 
 * Runtime: 4 ms (91.96% Better)
 * Memory Usage: 6.3 MB (67.15% Better)
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
  struct ListNode* del = node->next;
  node->val = del->val;
  node->next = del->next;
  free(del);
}