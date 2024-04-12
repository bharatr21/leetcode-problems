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
    int dfs(TreeNode* cur, TreeNode* parent, int len) {
        if(!cur) return len;
        len = ((parent && cur->val == parent->val + 1) ? len + 1 : 1);
        return max(len, max(dfs(cur->left, cur, len), dfs(cur->right, cur, len)));
    }

    int longestConsecutive(TreeNode* root) {
        return dfs(root, NULL, 0);
    }
};