// 
// firstNotRepeatingCharacter
// 
// Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.
// 
// Example
// 
// For s = "abacabad", the output should be
// firstNotRepeatingCharacter(s) = 'c'.
// 
// There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.
// 
// For s = "abacabaabacaba", the output should be
// firstNotRepeatingCharacter(s) = '_'.
// 
// There are no characters in this string that do not repeat.
// 

char firstNotRepeatingCharacter(char * s) {
    int pos[256] = {0};
    int count[256] = {0};
    char c[256] = {0};
    
    int nextpos = 1;
    for (char *p = s; *p != '\0'; p++) {
        if (pos[*p] == 0) {
            pos[*p] = nextpos++;
            c[pos[*p]] = *p;
        }
        count[pos[*p]]++;
    }
    
    for (int i = 0; i < nextpos; i++) {
        if (count[i] == 1)
            return c[i];
    }
    
    return '_';
}

