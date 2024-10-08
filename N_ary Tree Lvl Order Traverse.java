/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private void dfs(Node cur, List<List<Integer>> rez, int depth) {
        if(depth == rez.size()) {
            rez.add(new LinkedList<Integer>());
        }
        rez.get(depth).add(cur.val);
        for(var next : cur.children) {
            dfs(next, rez, depth + 1);
        }
    }
        
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null) { return new LinkedList<>(); }
        List<List<Integer>> rez = new LinkedList<>();
        dfs(root, rez, 0);
        return rez;
    }
}
