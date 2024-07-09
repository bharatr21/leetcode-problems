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
    bool isLeaf(TreeNode* node) {
        return (node && !node->left && !node->right);
    }
    int helper(TreeNode* node) {
        if(!node) return 0;
        if(isLeaf(node)) return 1;
        int depth;
        if(node->left && node->right) {
            depth = min(helper(node->left), helper(node->right));
        }
        else if(node->left) depth = helper(node->left);
        else depth = helper(node->right);
        return 1 + depth;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return helper(root);
    }
};