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
        if(root->val < low) return right; 
        else if(root->val > high) return left;
        else return root->val + left + right;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        else return sumHelper(root, low, high);
    }
};