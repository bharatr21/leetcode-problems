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
    TreeNode* lca(TreeNode* root, vector<TreeNode*> &nodes) {
        if(!root) return NULL;
        for(auto node: nodes) {
            if(root == node) return root;
        }
        TreeNode* left = lca(root->left, nodes);
        TreeNode* right = lca(root->right, nodes);
        if(left && right) return root;
        return ((left) ? left: right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(!root) return NULL;
        return lca(root, nodes);
    }
};