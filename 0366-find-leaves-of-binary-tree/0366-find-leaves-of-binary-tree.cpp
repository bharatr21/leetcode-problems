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
    int height(vector<vector<int>>& res, TreeNode* node) {
        if(!node) return -1;
        int lefth = height(res, node->left);
        int righth = height(res, node->right);
        int curh = 1 + max(lefth, righth);
        if(res.size() == curh) res.resize(curh + 1);
        res[curh].push_back(node->val);
        return curh;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        height(res, root);
        return res;
    }
};