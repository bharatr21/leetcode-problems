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
    int good;
    void dfs(TreeNode* root, int mx) {
        if(!root) return;
        if(mx <= root->val) {
            mx = root->val;
            good++;
        }
        dfs(root->left, max(mx, root->val));
        dfs(root->right, max(mx, root->val));
    }

    int goodNodes(TreeNode* root) {
        int mx = -10001;
        good = 0;
        if(!root) return good;
        dfs(root, mx);
        return good;
    }
};