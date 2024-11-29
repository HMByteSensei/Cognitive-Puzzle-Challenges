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
class Solution {
    private boolean dfs(TreeNode leftChild, TreeNode rightChild) {
        if(leftChild == null || rightChild == null) {
            return leftChild == rightChild;
        }
        return (leftChild.val == rightChild.val && 
                dfs(leftChild.left, rightChild.right) &&
                dfs(rightChild.left, leftChild.right));
    }
    public boolean isSymmetric(TreeNode root) {
        if(root == null) {
            return true;
        }
        // return dfs(root.left, root.right);
        Queue<TreeNode> red = new LinkedList<>();
        red.offer(root.left);
        red.offer(root.right);
        while(!red.isEmpty()) {
            TreeNode leftChild = red.poll();
            TreeNode rightChild = red.poll();
            if(leftChild == null || rightChild == null) {
                if(rightChild == leftChild) {
                    continue;
                }
                return false;
            }
            if(leftChild.val != rightChild.val) {
                return false;
            }
            red.offer(leftChild.left);
            red.offer(rightChild.right);
            red.offer(leftChild.right);
            red.offer(rightChild.left);
        }
        return true;
    }
}
