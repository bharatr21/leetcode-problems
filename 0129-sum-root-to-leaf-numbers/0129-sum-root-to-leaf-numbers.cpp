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
        return node && !node->left && !node->right;
    }

    int helper(TreeNode* node, int sum, int cur) {
        cur = cur * 10 + node->val;
        if(isLeaf(node)) return cur;
        int tmp = sum;
        if(node->left) sum += helper(node->left, tmp, cur);
        if(node->right) sum += helper(node->right, tmp, cur);
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return helper(root, 0, 0);
    }
};