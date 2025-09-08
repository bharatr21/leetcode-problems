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
        return max(lh, rh) + 1;
    }

    int diameter(TreeNode* root) {
        if(!root) return 0;
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        int lh = height(root->left);
        int rh = height(root->right);
        return max(max(ld, rd), lh + rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        return diameter(root); 
    }
};