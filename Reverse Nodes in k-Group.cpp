class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int n = 0;
        for(ListNode tmp = head; tmp != null; tmp=tmp.next, n++) {}

        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        while(n / k != 0) {
            ListNode cur = pre.next;
            for(int i=0; i<k-1; i++) {
                ListNode forward = cur.next;
                cur.next = forward.next;
                forward.next = pre.next;
                pre.next = forward;
            }
            pre = cur;
            n -= k;
        }
        return dummy.next;
    }
}
