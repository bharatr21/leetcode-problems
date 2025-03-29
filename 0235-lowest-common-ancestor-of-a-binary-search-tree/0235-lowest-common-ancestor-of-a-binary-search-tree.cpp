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
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return NULL;
        if(node == p || node == q) return node;
        if(min(p->val, q->val) >= node->val) return lca(node->right, p, q);
        else if(max(p->val, q->val) <= node->val) return lca(node->left, p, q);
        else return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        return lca(root, p, q);
    }
};