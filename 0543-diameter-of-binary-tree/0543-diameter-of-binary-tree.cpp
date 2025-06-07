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
    int diameter;
    int helper(TreeNode* root) {
        if(!root) return -1;
        int ld = helper(root->left);
        int rd = helper(root->right);
        diameter = max(diameter, ld + rd + 2);
        return max(ld, rd) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return -1;
        diameter = 0;
        helper(root);
        return diameter;
    }
};