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
    std::string helper(TreeNode *root, std::unordered_map<std::string, int> &m, std::vector<TreeNode*> &rez) {
        if(!root) {
            return "";
        }
        
        std::string leftNode = helper(root->left, m, rez);
        std::string rightNode = helper(root->right, m, rez);
    
        std::string encode = std::to_string(root->val) + ", " + leftNode +", " + rightNode;
        
        if(m.find(encode) != m.end() && m[encode] == 1) {
            rez.push_back(root);
        }
        m[encode]++;
        
        return encode;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::unordered_map<std::string, int> mapa;
        std::vector<TreeNode*> rez;
        helper(root, mapa, rez);
        // for(auto x : rez) {
        //     std::cout << x->val << "  ";
        // }
        return rez;
    }
};
