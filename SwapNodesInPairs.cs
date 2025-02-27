/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        var tmp = head.next;
        head.next = tmp.next;
        tmp.next = head;
        head = tmp;
        ListNode newHead = SwapPairs(head.next.next);
        if(head.next != null && head.next.next != null) {
            head.next.next = newHead;
        }
        return head;
    }
}
