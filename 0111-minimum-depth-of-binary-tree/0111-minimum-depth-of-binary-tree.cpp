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

// Note: Meta SWE E5 2024 - Phone Screen 
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node && (!node->left) && (!node->right);
    }
    int minD(TreeNode* root) {
        if(isLeaf(root)) return 1;
        int depth = INT_MAX - 1;
        if(root->left) depth = min(depth, minD(root->left));
        if(root->right) depth = min(depth, minD(root->right));
        return 1 + depth;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(isLeaf(root)) return 1;
        return minD(root);
    }
};