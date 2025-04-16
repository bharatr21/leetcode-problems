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
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void helper(vector<vector<int>>& heights, TreeNode* node) {
        int curHeight = height(node);
        heights[curHeight - 1].push_back(node->val);
        if(node->left) helper(heights, node->left);
        if(node->right) helper(heights, node->right);
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> heights;
        if(!root) return heights;
        int totHeight = height(root);
        heights.resize(totHeight + 1);
        helper(heights, root);
        heights.pop_back();
        return heights;
    }
};