/*
 * 3. Longest Substring Without Repeating Characters
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 *   Input: "abcabcbb"
 *   Output: 3 
 *   Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 *   Input: "bbbbb"
 *   Output: 1
 *   Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 *   Input: "pwwkew"
 *   Output: 3
 *   Explanation: The answer is "wke", with the length of 3. 
 * 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
func lengthOfLongestSubstring(s string) int {
    n := len(s)
    set := make(map[byte]int)
    ans, i, j := 0, 0, 0
    for i < n && j < n {
        _, exists := set[s[j]]
        if !exists {
            set[s[j]] = j
            j++
            if ans < j - i {
                ans = j - i
            }
        } else {
            delete(set, s[i])
            i++
        }
    }
    return ans
}
