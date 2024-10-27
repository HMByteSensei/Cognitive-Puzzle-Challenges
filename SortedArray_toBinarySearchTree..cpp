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
    TreeNode* helper(std::vector<int>& nums, int start, int end) {
        if(start >= end) {
            return nullptr;
        }
        int index = (end - start) / 2 + start;
        
        TreeNode *cur = new TreeNode(nums[index]);
        
        cur->left = helper(nums, start, index);
        cur->right = helper(nums, index + 1, end);
        return cur;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};
