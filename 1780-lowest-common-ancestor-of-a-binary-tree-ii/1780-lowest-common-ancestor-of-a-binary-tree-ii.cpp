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
        if(root == node) return true;
        if(!root) return false;
        return exists(root->left, node) || exists(root->right, node);
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        if(!p) return q;
        if(!q) return p;
        TreeNode* llca = lca(root->left, p, q);
        TreeNode* rlca = lca(root->right, p, q);
        if(llca && rlca) return root;
        return ((llca) ? llca : rlca);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !exists(root, p) || !exists(root, q)) return nullptr;
        return lca(root, p, q);
    }
};