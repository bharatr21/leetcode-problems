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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return -1;
        vector<vector<int>> lvls;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto [node, lvl] = q.front();
            q.pop();
            if(lvls.size() <= lvl) lvls.resize(lvl + 1);
            lvls[lvl].push_back(node->val);
            if(node->left) q.push({node->left, lvl+1});
            if(node->right) q.push({node->right, lvl+1});
        }
        int n = lvls.size();
        return lvls[n-1][0];
    }
};