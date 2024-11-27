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
    private HashMap<Integer, Integer> mapa;
    private TreeNode dfs(int[] in, int[] pre, int inStart, int inEnd, int[] prePos) {
        if(inStart > inEnd) {
            prePos[0]--;
            return null;
        }
        TreeNode cur = new TreeNode(pre[prePos[0]]);
        int inPosition = mapa.get(pre[prePos[0]]);
        prePos[0]++;
        cur.left = dfs(in, pre, inStart, inPosition - 1, prePos);
        prePos[0]++;
        cur.right = dfs(in, pre, inPosition + 1, inEnd, prePos);
        return cur;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(inorder.length == 0) { return null; }
        mapa = new HashMap<>();
        for(int i=0; i<inorder.length; i++) {
            mapa.put(inorder[i], i);
        }
        int[] prePos = {0};
        return dfs(inorder, preorder, 0, inorder.length - 1, prePos);
    }
}
