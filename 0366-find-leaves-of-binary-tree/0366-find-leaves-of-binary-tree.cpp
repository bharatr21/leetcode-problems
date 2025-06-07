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
    int getHeight(TreeNode* node, vector<vector<int>>& heights) {
        if(!node) {
            heights[0].push_back(-1);
            return 0;
        }
        int lh = getHeight(node->left, heights);
        int rh = getHeight(node->right, heights);
        int resh = 1 + max(lh, rh);
        if(heights.size() <= resh) heights.resize(resh + 1);
        heights[resh].push_back(node->val);
        return resh;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res, heights;
        heights.push_back({});
        if(!root) return res;
        getHeight(root, heights);
        int n = heights.size();
        for(int i = 1; i < n; i++) {
            res.push_back(heights[i]);
        }
        return res;
    }
};