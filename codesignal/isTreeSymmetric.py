# 
# isTreeSymmetric
# 
# Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.
# 
# Example
# 
# For
# 
# t = {
#     "value": 1,
#     "left": {
#         "value": 2,
#         "left": {
#             "value": 3,
#             "left": null,
#             "right": null
#         },
#         "right": {
#             "value": 4,
#             "left": null,
#             "right": null
#         }
#     },
#     "right": {
#         "value": 2,
#         "left": {
#             "value": 4,
#             "left": null,
#             "right": null
#         },
#         "right": {
#             "value": 3,
#             "left": null,
#             "right": null
#         }
#     }
# }
# the output should be isTreeSymmetric(t) = true.
# 
# Here's what the tree in this example looks like:
# 
#     1
#    / \
#   2   2
#  / \ / \
# 3  4 4  3
# As you can see, it is symmetric.
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
#         "value": 2,
#         "left": null,
#         "right": {
#             "value": 3,
#             "left": null,
#             "right": null
#         }
#     }
# }
# the output should be isTreeSymmetric(t) = false.
# 
# Here's what the tree in this example looks like:
# 
#     1
#    / \
#   2   2
#    \   \
#    3    3
# As you can see, it is not symmetric.
#
# Definition for binary tree:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None

def isMirror(root1, root2):
    if root1 == None and root2 == None:
        return True
    
    if root1 != None and root2 != None:
        if root1.value != root2.value:
            return False
        ret1 = isMirror(root1.left, root2.right)
        ret2 = isMirror(root1.right, root2.left)
        return (ret1 and ret2)
        
    return False
    
def isTreeSymmetric(t):
    if t == None:
        return True
    
    return isMirror(t.left, t.right)

