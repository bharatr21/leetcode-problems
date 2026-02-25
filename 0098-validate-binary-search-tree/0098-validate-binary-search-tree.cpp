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
    bool isValid(TreeNode* root, TreeNode* low, TreeNode* high) {
        bool res = true;
        if((low && root->val <= low->val) || (high && root->val >= high->val)) return false;
        if(root->left) res = res && isValid(root->left, low, root);
        if(root->right) res = res && isValid(root->right, root, high);
        return res;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isValid(root, nullptr, nullptr);
    }
};