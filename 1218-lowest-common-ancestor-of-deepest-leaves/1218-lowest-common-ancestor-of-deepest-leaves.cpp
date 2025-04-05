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
    TreeNode* lca(TreeNode* root, vector<TreeNode*> nodes) {
        if(!root) return root;
        for(auto& node: nodes) {
            if(root == node) return root;
        }
        TreeNode* left = lca(root->left, nodes);
        TreeNode* right = lca(root->right, nodes);
        if(left && right) return root;
        return ((left) ? left : right);
    }
    void helper(TreeNode* root, int depth, vector<vector<TreeNode*>>& nodes) {
        if(nodes.size() <= depth) nodes.resize(depth + 1);
        nodes[depth].push_back(root);
        if(root->left) helper(root->left, depth+1, nodes);
        if(root->right) helper(root->right, depth+1, nodes);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<TreeNode*>> nodes;
        if(!root) return root;
        helper(root, 0, nodes);
        int n = nodes.size();
        if(n <= 1) return root;
        vector<TreeNode*> tmp = nodes[n-1];
        return lca(root, tmp);
    }
};