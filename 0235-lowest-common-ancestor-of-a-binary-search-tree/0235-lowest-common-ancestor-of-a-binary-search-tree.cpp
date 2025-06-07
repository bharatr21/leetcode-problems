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
        if(root == p || root == q) return root;
        if(!root) return root;
        if(!p) return q;
        if(!q) return p;
        TreeNode* llca = lca(root->left, p, q);
        TreeNode* rlca = lca(root->right, p, q);
        if(llca && rlca) return root;
        else return ((llca) ? llca : rlca);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        return lca(root, p, q);
    }
};