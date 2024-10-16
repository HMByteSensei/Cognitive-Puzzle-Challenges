/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* prev = nullptr;
    bool dfs(TreeNode* root) {
        if(!root) {
            return true;
        }
        if(dfs(root->left) == false) {
            return false;
        }
        if(prev && prev->val >= root->val) {
            return false;
        }
        prev = root;
        if(dfs(root->right) == false) {
            return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};
