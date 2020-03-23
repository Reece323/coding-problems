// 
// checkPalindrome
// 
// Given the string, check if it is a palindrome.
// 
// Example
// 
// For inputString = "aabaa", the output should be
// checkPalindrome(inputString) = true;
// For inputString = "abac", the output should be
// checkPalindrome(inputString) = false;
// For inputString = "a", the output should be
// checkPalindrome(inputString) = true.
// 

bool checkPalindrome(char * inputString) {
    int i = 0, j = strlen(inputString)-1;
    while (i < j) {
        if (inputString[i++] != inputString[j--])
            return false;
    }
    return true;
}

