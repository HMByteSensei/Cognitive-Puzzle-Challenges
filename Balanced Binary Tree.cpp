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
    int helper(TreeNode* cur, int &max_hight) {
        if(!cur) return 0;
        
        int left_child = helper(cur->left, max_hight);
        int right_child = helper(cur->right, max_hight);
        
        if(std::abs(left_child - right_child) > max_hight) {
            max_hight = std::abs(left_child - right_child);
        }
        return std::max(left_child, right_child) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int max = 0;
        helper(root, max);
        return max <= 1;
    }
};
