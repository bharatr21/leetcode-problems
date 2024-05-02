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
        vector<vector<int>> v;
        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        if(!root) return res;
        q.push({root, 0});
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(v.size() <= lvl) v.resize(lvl + 1);
            v[lvl].push_back(node->val);
            if(node->right) q.push({node->right, lvl + 1});
            if(node->left) q.push({node->left, lvl + 1});
        }
        for(int i = 0; i < v.size(); i++)
        {
            res.push_back(v[i][0]);
        }
        return res;
    }
};