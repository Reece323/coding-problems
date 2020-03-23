// 
// isListPalindrome
// 
// Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l, since this is what you'll be asked to do during an interview.
// 
// Given a singly linked list of integers, determine whether or not it's a palindrome.
// 
// Note: in examples below and tests preview linked lists are presented as arrays just for simplicity of visualization: in real data you will be given a head node l of the linked list
// 
// Example
// 
// For l = [0, 1, 0], the output should be
// isListPalindrome(l) = true;
// 
// For l = [1, 2, 2, 3], the output should be
// isListPalindrome(l) = false.
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
bool isListPalindrome(list_integer * l) {
    list_integer *ptr, *p1, *p2, *head, *next, *prev, *mid;
    int len = 0;
    bool ans = true;
    
    if (l == NULL)
        return true;
    
    // get length of list
    ptr = l;
    while (ptr) {
        len++;
        ptr = ptr->next;
    }
    
    // get mid point in list
    int m = len / 2;
    mid = l;
    for (int i = 0; i < m; i++) {
        mid = mid->next;
    }
    
    // reverse second half
    prev = NULL;
    ptr = mid;
    while (ptr) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    mid = prev;

    // compare the two halves
    p1 = l;
    p2 = mid;
    while (ans && p2 && p1) {
        if (p1->value != p2->value)
            ans = false;
        p1 = p1->next;
        p2 = p2->next;
    }
    
    // re-reverse second half
    prev = NULL;
    ptr = mid;
    while (ptr) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    mid = prev;

    return ans;
}

