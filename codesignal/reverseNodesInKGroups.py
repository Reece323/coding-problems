# reverseNodesInKGroups
# 
# Note: Your solution should have O(n) time complexity, where n is the number of elements in l, and O(1) additional space complexity, since this is what you would be asked to accomplish in an interview.
# 
# Given a linked list l, reverse its nodes k at a time and return the modified list. k is a positive integer that is less than or equal to the length of l. If the number of nodes in the linked list is not a multiple of k, then the nodes that are left out at the end should remain as-is.
# 
# You may not alter the values in the nodes - only the nodes themselves can be changed.
# 
# Example
#   For l = [1, 2, 3, 4, 5] and k = 2, the output should be
#     reverseNodesInKGroups(l, k) = [2, 1, 4, 3, 5];
#   For l = [1, 2, 3, 4, 5] and k = 1, the output should be
#     reverseNodesInKGroups(l, k) = [1, 2, 3, 4, 5];
#   For l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] and k = 3, the output should be
#     reverseNodesInKGroups(l, k) = [3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11].
# 
# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#

def reverseNodesInKGroups(l, k):
    p1 = l
    p2 = None
    stack = []
    while p1:
        p2 = p1
        i = 0
        while p2 and i < k:
            stack.append(p2.value)
            p2 = p2.next
            i += 1
        reverse = (i == k)
        while p1 and len(stack) > 0:
            val = stack.pop()
            if reverse:
                p1.value = val
            p1 = p1.next
        p1 = p2
    return l

