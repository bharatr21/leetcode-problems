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
    TreeNode* helper(TreeNode* root, TreeNode* parent, TreeNode* sibling) {
        if(!root) return parent;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->right = parent;
        root->left = sibling;
        return helper(left, root, right);
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        return helper(root, nullptr, nullptr);
    }
};