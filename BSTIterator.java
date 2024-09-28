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
