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
    void inOrder(TreeNode* node, unordered_map<int, TreeNode*>& mp, vector<int>& res) {
        if(!node) return;
        inOrder(node->left, mp, res);
        int idx = res.size();
        mp[idx] = node;
        res.push_back(node->val);
        inOrder(node->right, mp, res);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        vector<int> res;
        unordered_map<int, TreeNode*> mp;
        inOrder(root, mp, res);
        int n = res.size(), i;
        for(i = n - 2; i >= 0; i--)
        {
            res[i] += res[i+1];
        }
        for(auto el: res) cout << el << ' ';
        cout << endl;
        for(i = 0; i < n; i++)
        {
            mp[i]->val = res[i];
        }
        return root;
    }
};