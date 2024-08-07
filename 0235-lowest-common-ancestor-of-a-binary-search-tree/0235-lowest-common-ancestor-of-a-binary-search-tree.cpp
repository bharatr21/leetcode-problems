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
        if(!root || !p || !q || root == p || root == q) return root;
        int curval = root->val;
        int pval = p->val;
        int qval = q->val;
        if(pval > curval && qval > curval) return lca(root->right, p, q);
        else if(pval < curval && qval < curval) return lca(root->left, p, q);
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};