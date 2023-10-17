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
    int height(TreeNode* root)
    {
        if(!root) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 + max(left_height, right_height);
    }
    int diameter(TreeNode* root) {
        if(!root) return 0;
        int left_dia = diameter(root->left);
        int right_dia = diameter(root->right);
        //Diameter may or may not pass through the root
        return max(max(left_dia, right_dia), height(root->left) + height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
    }
};