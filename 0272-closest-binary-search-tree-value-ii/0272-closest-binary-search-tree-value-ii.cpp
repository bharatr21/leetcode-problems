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
        if(!root || !k) return res;
        inOrder(root, vals);
        int n = vals.size();
        int diff = INT_MAX, st = -1;
        for(int i = 0; i < n; i++) {
            if(abs(vals[i] - target) < diff) {
                diff = abs(vals[i] - target);
                st = i;
            }
        }
        int left = st, right = st + 1;
        while(right - left - 1 < k) {
            if(left < 0) right++;
            else if(right == n || abs(vals[left] - target) <= abs(vals[right] - target)) {
                left--;
            } else right++;
        }
        for(int i = left + 1; i < right; i++) res.push_back(vals[i]);
        return res;
    }
};