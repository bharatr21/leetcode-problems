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
        if(!root) return res;
        map<int, vector<pair<int, int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while(!q.empty()) {
            auto [node, row, col] = q.front();
            mp[col].push_back({row, node->val});
            q.pop();
            if(node->left) q.push({node->left, row+1, col-1});
            if(node->right) q.push({node->right, row+1, col+1});
        }
        vector<int> tmp;
        for(auto& item: mp) {
            sort(item.second.begin(), item.second.end());
            for(auto& el: item.second) tmp.push_back(el.second);
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};