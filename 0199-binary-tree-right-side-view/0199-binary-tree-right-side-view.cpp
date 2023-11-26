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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<vector<int>> store;
        queue<pair<TreeNode*, int>> q;
        if(!root) return res;
        q.push({root, 0});
        while(!q.empty())
        {
            auto [node, lvl] = q.front();
            q.pop();
            if(store.size() <= lvl) store.resize(lvl + 1);
            store[lvl].push_back(node->val);
            if(node->left) q.push({node->left, lvl+1});
            if(node->right) q.push({node->right, lvl+1});
        }
        int n = store.size(), i;
        for(i = 0; i < n; i++)
        {
            res.push_back(store[i].back());
        }
        return res;
    }
};