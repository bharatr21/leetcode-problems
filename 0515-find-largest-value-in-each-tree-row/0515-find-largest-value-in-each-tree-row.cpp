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
    vector<int> largestValues(TreeNode* root) {
       queue<pair<TreeNode*, int>> q;
       vector<int> res;
       vector<vector<int>> store;
       if(!root) return res;
       q.push({root, 0});
       while(!q.empty())
       {
           auto [node, lvl] = q.front();
           q.pop();
           if(store.size() <= lvl) store.resize(lvl + 1);
           store[lvl].push_back(node->val);
           if(node->left) q.push({node->left, lvl + 1});
           if(node->right) q.push({node->right, lvl + 1});
       }
       for(auto v: store)
       {
           res.push_back(*max_element(v.begin(), v.end()));
       }
       return res;
    }
};