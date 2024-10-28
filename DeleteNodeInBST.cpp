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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *target = root, *prev = nullptr;
        while(target && target->val != key) {
            prev = target;
            if(target->val < key) { target = target->right; }
            else { target = target->left; }
        }
        if(!target) { return root; } // case 0

        // if(!target->left && !target->right) {
        //     if(!prev) root = nullptr; // if prev == nullptr meaning root == target
        //     else if(prev->left == target) prev->left = nullptr;
        //     else prev->right = nullptr;
        // } else if(!target->right) {
        //     if(!prev) root = root->left; 
        //     else if(prev->left == target) prev->left = target->left;
        //     else prev->right = target->left;    
        // } else if(!target->left) {
        //     if(!prev) root = root->right; 
        //     else if(prev->left == target) prev->left = target->right;
        //     else prev->right = target->right;
        // }
        if(!target->left || !target->right) { // case 1, 2, 3 put together
            TreeNode* child = target->left ? target->left : target->right;
            if(!prev) root = child; // if prev == nullptr meaning root == target
            else if(prev->left == target) prev->left = child;
            else prev->right = child;
        } else {
            TreeNode* cur = target;
            prev = target;
            target=target->right;
            while(target->left) { prev=target; target = target->left; }
            cur->val = target->val;
            if(prev->left == target) { prev->left = target->right; }
            else { prev->right = target->right; }
        }
        delete target;
        return root;
    }
};
