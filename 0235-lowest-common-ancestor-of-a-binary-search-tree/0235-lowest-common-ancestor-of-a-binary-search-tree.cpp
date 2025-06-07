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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        if(!p) return q;
        if(!q) return p;
        TreeNode *left = root->left, *right = root->right;
        if(root->val > max(p->val, q->val)) return lca(root->left, p, q);
        else if(root->val < min(p->val, q->val)) return lca(root->right, p, q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        return lca(root, p, q);
    }
};