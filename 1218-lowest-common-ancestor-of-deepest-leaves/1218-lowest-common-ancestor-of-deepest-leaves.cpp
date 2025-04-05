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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(!p) return q;
        if(!q) return p;
        if(root == p || root == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left && right) return root;
        else return ((left) ? left : right);
    }

    void helper(vector<vector<TreeNode*>>& depths, int d, TreeNode* node) {
        if(depths.size() <= d) depths.resize(d + 1);
        depths[d].push_back(node);
        if(node->left) helper(depths, d+1, node->left);
        if(node->right) helper(depths, d+1, node->right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<TreeNode*>> depths;
        if(!root) return root;
        helper(depths, 0, root);
        int n = depths.size();
        if(n <= 1) return root;
        TreeNode* node;
        // for(auto& d: depths) {
        //     for(auto& nd: d) {
        //         cout << nd->val << ' ';
        //     }
        //     cout << endl;
        // }
        if(depths[n-1].size() >= 2) {
            node = lca(root, depths[n-1][0], depths[n-1][1]);
            for(int i = 2; i < depths[n-1].size(); i++) {
                node = lca(root, node, depths[n-1][i]);
            }
        } else node = depths[n-1][0];
        return node;
    }
};