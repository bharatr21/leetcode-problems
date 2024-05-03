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
    bool isValid(TreeNode* root, long mn, long mx) {
        if(!root) return true;
        if(root->val <= mn || root->val >= mx) return false;
        bool lt = isValid(root->left, mn, root->val);
        bool rt = isValid(root->right, root->val, mx);
        return lt && rt;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};