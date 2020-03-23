#
# traverseTree
# 
# Note: Try to solve this task without using recursion, since this is what you'll be asked to do during an interview.
# 
# Given a binary tree of integers t, return its node values in the following format:
# 
# The first element should be the value of the tree root;
# The next elements should be the values of the nodes at height 1 (i.e. the root children), ordered from the leftmost to the rightmost one;
# The elements after that should be the values of the nodes at height 2 (i.e. the children of the nodes at height 1) ordered in the same way;
# Etc.
# Example
# 
# For
# 
# t = {
#     "value": 1,
#     "left": {
#         "value": 2,
#         "left": null,
#         "right": {
#             "value": 3,
#             "left": null,
#             "right": null
#         }
#     },
#     "right": {
#         "value": 4,
#         "left": {
#             "value": 5,
#             "left": null,
#             "right": null
#         },
#         "right": null
#     }
# }
# the output should be
#   traverseTree(t) = [1, 2, 4, 3, 5].
# 
# This t looks like this:
# 
#      1
#    /   \
#   2     4
#    \   /
#     3 5
#
# Definition for binary tree:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None

def traverseTree(t):
    q = [t]
    ret = []

    while q:
        node = q.pop(0)
        if node == None:
            break
        ret.append(node.value)
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)
            
    return ret

