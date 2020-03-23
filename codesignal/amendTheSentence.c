// 
// amendTheSentence
// 
// You have been given a string s, which is supposed to be a sentence. However, someone forgot to put spaces between the different words, and for some reason they capitalized the first letter of every word. Return the sentence after making the following amendments:
// 
// Put a single space between the words.
// Convert the uppercase letters to lowercase.
// Example
// 
// For s = "CodesignalIsAwesome", the output should be
// amendTheSentence(s) = "codesignal is awesome";
// For s = "Hello", the output should be
// amendTheSentence(s) = "hello".
// 

char * amendTheSentence(char * s) {
    char *ans = malloc(128);
    int i, j;
    
    j = 0;
    for (i = 0; i < strlen(s); i++) {
        if (isupper(s[i])) {
            if (i > 0)
                ans[j++] = ' ';
            ans[j++] = tolower(s[i]);
        } else {
            ans[j++] = s[i];
        }
    }
    ans[j++] = '\0';
    
    return ans;
}

