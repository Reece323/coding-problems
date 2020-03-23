// 
// addTwoHugeNumbers
// 
// You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.
// 
// Example
// 
// For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
// addTwoHugeNumbers(a, b) = [9876, 5434, 0].
// 
// Explanation: 987654321999 + 18001 = 987654340000.
// 
// For a = [123, 4, 5] and b = [100, 100, 100], the output should be
// addTwoHugeNumbers(a, b) = [223, 104, 105].
// 
// Explanation: 12300040005 + 10001000100 = 22301040105.
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

list_integer * reverseList(list_integer *l) {
    list_integer *temp, *prev = NULL;
    list_integer *ptr = l;
    while (ptr) {
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev;
}

list_integer * addTwoHugeNumbers(list_integer * a, list_integer * b) {
    if (a != NULL && b == NULL)
        return a;
    if (b != NULL && a == NULL)
        return b;
    
    // reverse the lists to process least significant digits first.
    a = reverseList(a);
    b = reverseList(b);
    
    list_integer *c = calloc(1, sizeof(list_integer));
    list_integer *p1 = a, *p2 = b, *p3 = c, *next = NULL;
    while (p1 || p2) {
        int sum = 0, carry = 0;
        if (p1) {
            sum += p1->value;
            p1 = p1->next;
        }
        if (p2) {
            sum += p2->value;
            p2 = p2->next;
        }
        p3->value += sum;
        if (p3->value >= 10000) {
            carry = p3->value / 10000;
            p3->value = p3->value % 10000;
        }
        if (carry || p1 || p2) {
            p3->next = calloc(1, sizeof(list_integer));
            p3->next->value = carry;
            p3 = p3->next;
        }
    }
    
    // reverse the lists again to return them back to original order.
    a = reverseList(a);
    b = reverseList(b);
    c = reverseList(c);
    
    return c;
}

