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
    int sumHelper(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int left = sumHelper(root->left, low, high);
        int right = sumHelper(root->right, low, high);
        if(root->val > high) return left;
        else if(root->val < low) return right;
        else return left + root->val + right;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        return sumHelper(root, low, high);
    }
};