/*
 * https://leetcode.com/problems/merge-two-sorted-lists/submissions/
 *  
 * Code:  7:39 
 *  CPU:   5ms (43.79%)
 *  MEM: 6.1MB (35.79%)
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* merged = NULL;
    struct ListNode* merged_head = NULL;
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
    
    if (list1 != NULL)
        merged->next = list1;
    if (list2 != NULL)
        merged->next = list2;

    return merged_head;
}