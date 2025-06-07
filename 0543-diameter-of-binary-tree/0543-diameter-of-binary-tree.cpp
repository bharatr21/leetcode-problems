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
    int height(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }

    int helper(TreeNode* root) {
        if(!root) return 0;
        int ld = helper(root->left);
        int rd = helper(root->right);
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh + rh, max(ld, rd));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        return helper(root);
    }
};