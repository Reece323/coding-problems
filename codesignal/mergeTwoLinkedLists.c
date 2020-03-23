// 
// mergeTwoLinkedLists
// 
// Note: Your solution should have O(l1.length + l2.length) time complexity, since this is what you will be asked to accomplish in an interview.
// 
// Given two singly linked lists sorted in non-decreasing order, your task is to merge them. In other words, return a singly linked list, also sorted in non-decreasing order, that contains the elements from both original lists.
// 
// Example
// 
// For l1 = [1, 2, 3] and l2 = [4, 5, 6], the output should be
// mergeTwoLinkedLists(l1, l2) = [1, 2, 3, 4, 5, 6];
// For l1 = [1, 1, 2, 4] and l2 = [0, 3, 5], the output should be
// mergeTwoLinkedLists(l1, l2) = [0, 1, 1, 2, 3, 4, 5].
// 
// Definition for singly-linked list:
// typedef struct list_##name {
//   type value;
//   struct list_##name *next;
// } list_##name;
//
// list_##name *alloc_list_##name(type v) {
//   list_##name *l = calloc(1, sizeof(list_##name));
//   l->value = v;
//   return l;
// }
//

list_integer * mergeTwoLinkedLists(list_integer * l1, list_integer * l2) {
    list_integer *head = NULL, *cur = NULL, *prev = NULL;
    while (l1 || l2) {
        if (l1 != NULL && l2 == NULL) {
            cur = l1;
            l1 = l1->next;
        } else if (l2 != NULL && l1 == NULL) {
            cur = l2;
            l2 = l2->next;
        } else {
            if (l1->value <= l2->value) {
                cur = l1;
                l1 = l1->next;
            } else {
                cur = l2;
                l2 = l2->next;
            }
        }
        
        if (head == NULL)
            head = cur;
        
        if (prev)
            prev->next = cur;
        prev = cur;
    }
    return head;
}

