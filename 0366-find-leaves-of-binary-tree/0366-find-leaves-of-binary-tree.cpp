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
    int heightHelper(vector<vector<int>>& heights, TreeNode* node) {
        if(!node) return -1;
        int leftHeight = heightHelper(heights, node->left);
        int rightHeight = heightHelper(heights, node->right);
        int curHeight = 1 + max(leftHeight, rightHeight);
        if(heights.size() == curHeight) heights.push_back({});
        heights[curHeight].push_back(node->val);
        return curHeight;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> heights;
        if(!root) return heights;
        heightHelper(heights, root);
        return heights;
    }
};