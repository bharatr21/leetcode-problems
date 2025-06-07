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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* lnode = root->left;
        TreeNode* r = upsideDownBinaryTree(lnode);
        if(lnode) {
            TreeNode* rnode = root->right;
            lnode->left = rnode;
            lnode->right = root;
            root->left = nullptr;
            root->right = nullptr;
        }
        return ((r) ? r : root);
    }
};