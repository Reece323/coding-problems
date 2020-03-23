# 
# findProfession
# 
# Consider a special family of Engineers and Doctors. This family has the following rules:
# 
# Everybody has two children.
# The first child of an Engineer is an Engineer and the second child is a Doctor.
# The first child of a Doctor is a Doctor and the second child is an Engineer.
# All generations of Doctors and Engineers start with an Engineer.
# We can represent the situation using this diagram:
# 
#                 E
#            /         \
#           E           D
#         /   \        /  \
#        E     D      D    E
#       / \   / \    / \   / \
#      E   D D   E  D   E E   D
# Given the level and position of a person in the ancestor tree above, find the profession of the person.
# Note: in this tree first child is considered as left child, second - as right.
# 
# Example
#   For level = 3 and pos = 3, the output should be
#     findProfession(level, pos) = "Doctor".

def findProfession(level, pos):
    binary = str(bin(pos-1))[2:]
    prof = 0
    for i in reversed(binary):
        if int(i):
            prof = not prof

    if prof:
        return('Doctor')
    else:
        return('Engineer')

