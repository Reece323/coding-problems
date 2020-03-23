# rearrangeLastN
# 
# Note: Try to solve this task in O(list size) time using O(1) additional space, since this is what you'll be asked during an interview.
# 
# Given a singly linked list of integers l and a non-negative integer n, move the last n list nodes to the beginning of the linked list.
# 
# Example
#   For l = [1, 2, 3, 4, 5] and n = 3, the output should be
#     rearrangeLastN(l, n) = [3, 4, 5, 1, 2];
#   For l = [1, 2, 3, 4, 5, 6, 7] and n = 1, the output should be
#     rearrangeLastN(l, n) = [7, 1, 2, 3, 4, 5, 6].
# 
# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#

def rearrangeLastN(l, n):
    last = None
    tail = []
    
    if l is None:
        return None
    if n is 0:
        return l
        
    cur = l
    while cur:
        tail.append(cur)
        if len(tail) > n:
            last = tail.pop(0)
        cur = cur.next
    
    if last is None:
        return l
    
    head = tail[0]
    tail[n-1].next = l
    last.next = None
    return head

