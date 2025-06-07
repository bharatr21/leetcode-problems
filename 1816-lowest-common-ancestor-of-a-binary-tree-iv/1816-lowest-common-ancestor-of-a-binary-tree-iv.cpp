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
        if(!root) return root;
        for(TreeNode* node: nodes) {
            if(root == node) return root;
        }
        TreeNode* llca = lca(root->left, nodes);
        TreeNode* rlca = lca(root->right, nodes);
        if(llca && rlca) return root;
        return ((llca) ? llca : rlca);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(!root) return root;
        return lca(root, nodes);
    }
};