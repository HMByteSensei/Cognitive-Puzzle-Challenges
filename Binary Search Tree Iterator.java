/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    Stack<TreeNode> stack;
    public BSTIterator(TreeNode root) {
        stack = new Stack<>();
        stack.push(root);
        
        while(root.left != null) {
            stack.push(root.left);
            root = root.left;
        }
    }
    
    public int next() {
        TreeNode cur = stack.pop();
        int rez = cur.val;
        if(cur.right != null) {
            cur = cur.right;
            stack.push(cur);
            while(cur.left != null) {
                cur = cur.left;
                stack.push(cur);
            }
        }
        return rez;
    }
    
    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
