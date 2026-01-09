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
    TreeNode* lca(TreeNode* cur, vector<TreeNode*> nodes) {
        if(!cur) return cur;
        for(TreeNode* node: nodes) {
            if(cur == node) return cur;            
        }
        TreeNode* left = lca(cur->left, nodes);
        TreeNode* right = lca(cur->right, nodes);
        if(left && right) return cur;
        else return ((left) ? left : right);
    }

    void dfs(vector<vector<TreeNode*>>& depths, int depth, TreeNode* root) {
        if(depth >= depths.size()) depths.resize(depth + 1);
        depths[depth].push_back(root);
        if(root->left) dfs(depths, depth + 1, root->left);
        if(root->right) dfs(depths, depth + 1, root->right);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> depths;
        if(!root) return NULL;
        dfs(depths, 0, root);
        int last = depths.size() - 1;
        return lca(root, depths[last]);
    }
};