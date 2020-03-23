// 
// removeKFromList
// 
// Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in the list, since this is what you'll be asked to do during an interview.
// 
// Given a singly linked list of integers l and an integer k, remove all elements from list l that have a value equal to k.
// 
// Example
// 
// For l = [3, 1, 2, 3, 4, 5] and k = 3, the output should be
// removeKFromList(l, k) = [1, 2, 4, 5];
// For l = [1, 2, 3, 4, 5, 6, 7] and k = 10, the output should be
// removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7].
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

list_integer * removeKFromList(list_integer * l, int k) {
    list_integer *head = l;
    list_integer *prev = NULL;
    while (l != NULL) {
        if (l->value == k) {
            if (prev != NULL) {
                prev->next = l->next;
            }
            if (head == l) {
                head = l->next;
            }
        } else {
            prev = l;
        }
        l = l->next;
    }
    return head;
}

