# 
# areFollowingPatterns
# 
# Given an array strings, determine whether it follows the sequence given in the patterns array. In other words, there should be no i and j for which strings[i] = strings[j] and patterns[i] ≠ patterns[j] or for which strings[i] ≠ strings[j] and patterns[i] = patterns[j].
# 
# Example
# 
# For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
# areFollowingPatterns(strings, patterns) = true;
# For strings = ["cat", "dog", "doggy"] and patterns = ["a", "b", "b"], the output should be
# areFollowingPatterns(strings, patterns) = false.
# 

def areFollowingPatterns(strings, patterns):
    if len(strings) != len(patterns):
        return False
    
    test = {}
    for i in range(len(patterns)):
        if patterns[i] in test:
            if test[patterns[i]] != strings[i]:
                return False
        else:
            if strings[i] in test.values():
                return False
            test[patterns[i]] = strings[i]
    
    return True

