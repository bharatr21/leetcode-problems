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
    int dist(TreeNode* root, int target) {
        int mn = 10005;
        if(!root) return 10005;
        else if(root->val == target) return 0;
        else mn = min(mn, 1 + min(dist(root->left, target), dist(root->right, target)));
        return mn;
    }
    TreeNode* lca(TreeNode* root, int p, int q) {
        if(!root) return NULL;
        else if(root->val == p || root->val == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left && right) return root;
        return ((left) ? left : right);
    }

    int findDistance(TreeNode* root, int p, int q) {
        if(p == q) return 0;
        TreeNode* node = lca(root, p, q);
        int p_dist = dist(node, p);                      
        int q_dist = dist(node, q);
        return (p_dist + q_dist);
    }
};