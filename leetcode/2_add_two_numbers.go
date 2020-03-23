/*
 * 2. Add Two Numbers
 * 
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example:
 *   Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *   Output: 7 -> 0 -> 8
 *   Explanation: 342 + 465 = 807.
 * 
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var prev, out *ListNode
    carry := 0

    for l1 != nil || l2 != nil {
        n1 := 0
        n2 := 0
        if l1 != nil {
            n1 = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            n2 = l2.Val
            l2 = l2.Next
        }

        sum := n1 + n2 + carry
        carry = int(sum / 10)
        remainder := sum % 10

        cur := new(ListNode)
        if prev != nil {
            prev.Next = cur
        } else {
            out = cur
        }
        cur.Val = remainder
        prev = cur
    }

    if carry != 0 {
        cur := new(ListNode)
        cur.Val = carry
        prev.Next = cur
    }

    return out
}
