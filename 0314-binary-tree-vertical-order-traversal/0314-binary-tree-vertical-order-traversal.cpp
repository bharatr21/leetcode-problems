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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> levels;
        if(!root) return res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            levels[level].push_back(node->val);
            if(node->left) q.push({node->left, level - 1});
            if(node->right) q.push({node->right, level + 1});
        }
        for(auto it: levels) {
            res.push_back(it.second);
        }
        return res;
    }
};