/*
 * https://leetcode.com/problems/merge-two-sorted-lists/submissions/
 * Exact same code as logic as the C variation but I wanted to see what would happen
 *  
 * Code:  ~4:30
 *  CPU:    7ms (71.99%)
 *  MEM: 14.8MB (53.27%)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode* merged;
        struct ListNode* merged_head;
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val < list2->val){
            merged = list1;
            list1 = list1->next;
        } else {
            merged = list2;
            list2 = list2->next;
        }
        merged_head = merged;

        while ((list1 != NULL) && (list2 != NULL)){
            if (list1->val < list2->val){
                merged->next = list1;
                merged = merged->next;
                list1 = list1->next;
            } else {
                merged->next = list2;
                merged = merged->next;
                list2 = list2->next;
            }
        }

        if (list1 != NULL){
            merged->next = list1;
        }
        if (list2 != NULL){
            merged->next = list2;
        }
        return merged_head;
    }
};