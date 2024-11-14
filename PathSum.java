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
import java.util.AbstractMap;

class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) {
            return false;
        }
        if(root.left == null && root.right == null) {
            return root.val == targetSum;
        }
        return (hasPathSum(root.left, targetSum - root.val) ||
                hasPathSum(root.right, targetSum - root.val));
        // Stack<Map.Entry<TreeNode, Integer>> stack = new Stack<>();
        // stack.push(new AbstractMap.SimpleEntry<>(root, targetSum));
        // while(!stack.isEmpty()) {
        //     Map.Entry<TreeNode, Integer> cur = stack.pop();
        //     TreeNode node = cur.getKey();
        //     int target = cur.getValue();
        //     if(node.left == null && node.right == null && target == node.val) {
        //         return true;
        //     }
        //     if(node.left != null) {
        //         stack.push(new AbstractMap.SimpleEntry<>(node.left, target - 
        //                                                  node.val));
        //     } 
        //     if(node.right != null) {
        //         stack.push(new AbstractMap.SimpleEntry<>(node.right, target -
        //                                                 node.val));
        //     }
        // }
        // return false;
    }
}
