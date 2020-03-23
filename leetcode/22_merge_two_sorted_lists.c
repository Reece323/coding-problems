/*
 * 21. Merge Two Sorted Lists
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 *   Input: 1->2->4, 1->3->4
 *   Output: 1->1->2->3->4->4
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* prev = NULL;
    
    while (l1 != NULL || l2 != NULL) {
        prev = tail;
        if (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                tail = l1;
                l1 = l1->next;
            } else {
                tail = l2;
                l2 = l2->next;
            }
        } else if (l1 != NULL) {
            tail = l1;
            l1 = l1->next;
        } else if (l2 != NULL) {
            tail = l2;
            l2 = l2->next;
        }
        
        if (head == NULL)
            head = tail;
        if (prev != NULL)
            prev->next = tail;
    }
    
    return (head);
}
