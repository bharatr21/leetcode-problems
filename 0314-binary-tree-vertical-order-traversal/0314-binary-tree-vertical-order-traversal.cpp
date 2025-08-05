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
        if(!root) return res;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, vector<pair<int, int>>> levels;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto [node, coords] = q.front();
            auto [x, y] = coords;
            q.pop();
            levels[x].push_back({y, node->val});
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }
        for(auto lvl: levels) {
            // sort(lvl.second.begin(), lvl.second.end());
            vector<int> tmp;
            for(auto el: lvl.second) tmp.push_back(el.second);
            res.push_back(tmp);
        }
        return res;
    }
};