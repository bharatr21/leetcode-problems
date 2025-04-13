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
    void inOrder(TreeNode* root, vector<int>& vals) {
        if(root->left) inOrder(root->left, vals);
        vals.push_back(root->val);
        if(root->right) inOrder(root->right, vals);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> vals, res;
        if(!root) return res;
        inOrder(root, vals);
        sort(vals.begin(), vals.end(), [target](int a, int b) {
            return abs(a - target) < abs(b - target);
        });
        for(int i = 0; i < k; i++) res.push_back(vals[i]);
        return res;
    }
};