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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, vector<pair<int, int>>> mp;
        if(!root) return res;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto [node, level] = q.front();
            auto [col, row] = level;
            mp[col].push_back({row, node->val});
            q.pop();
            if(node->left) q.push({node->left, {col - 1, row + 1}});
            if(node->right) q.push({node->right, {col + 1, row + 1}});
        }
        for(auto u: mp) {
            sort(u.second.begin(), u.second.end());
            vector<int> tmp;
            for(auto it: u.second) tmp.push_back(it.second);
            res.push_back(tmp);
        }
        return res;
    }
};