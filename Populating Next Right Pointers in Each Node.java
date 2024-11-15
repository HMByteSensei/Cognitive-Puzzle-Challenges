/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    private void dfs(Node left) {
        if(left.left == null) {
            return;
        }
        Node cur = left;
        while(cur != null) {
            cur.left.next = cur.right;
            Node lastRight = cur.right;
            cur = cur.next;
            if(cur == null) {
                break;
            }
            lastRight.next = cur.left;
        }
        dfs(left.left);
    }
    
    public Node connect(Node root) {
        if(root == null || ((root.left == null) || (root.right == null))) {
            return root;
        }
        root.left.next = root.right;
        // dfs(root.left);
        // return root;
        Node cur = root.left;
        while(cur.left != null) {
            Node tmp = cur;
            while(tmp != null) {
                tmp.left.next = tmp.right;
                Node lastRight = tmp.right;
                tmp = tmp.next;
                if(tmp == null) {
                    break;
                }
                lastRight.next = tmp.left;
            }
            cur = cur.left;
        }
        return root;
    }
}
