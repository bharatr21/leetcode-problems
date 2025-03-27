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
    void helper(TreeNode* root, long& mn, long& sec) {
        if(mn > root->val) {
            sec = mn;
            mn = root->val;
        }
        else if(sec > root->val && root->val > mn) {
            sec = root->val;
        }
        if(root->left) helper(root->left, mn, sec);
        if(root->right) helper(root->right, mn, sec);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long mn = INT_MAX + 1L, secmn = INT_MAX + 1L;
        if(!root) return -1;
        helper(root, mn, secmn);
        return ((secmn == INT_MAX + 1L) ? -1: secmn);
    }
};