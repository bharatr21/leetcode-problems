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
    TreeNode* flip(TreeNode* root, TreeNode* parent, TreeNode* sibling) {
        if(!root) return parent;
        TreeNode* lnode = root->left;
        TreeNode* rnode = root->right;
        root->left = sibling;
        root->right = parent;
        return flip(lnode, root, rnode);
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return flip(root, NULL, NULL);
    }
};