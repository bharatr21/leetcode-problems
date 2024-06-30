/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exists(TreeNode* root, TreeNode* node) {
        if(!node || !root) return false;
        if(root == node) return true;
        return (exists(root->left, node) || exists(root->right, node));
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        if(!root) return NULL;
        if(!p) return q;
        if(!q) return p;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left && right) return root;
        return ((left) ? left : right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !exists(root, p) || !exists(root, q)) return NULL;
        return lca(root, p, q);
    }
};