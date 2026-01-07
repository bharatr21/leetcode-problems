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
    int treeSum(vector<int>& subSums, TreeNode* node) {
        if(!node) return 0;
        int lsum = treeSum(subSums, node->left);
        int rsum = treeSum(subSums, node->right);
        int tot = lsum + node->val + rsum;
        subSums.push_back(tot);
        return tot;
    }

    int maxProduct(TreeNode* root) {
        vector<int> subSums;
        if(!root) return 0;
        int total = treeSum(subSums, root);
        int res = 0;
        for(int& subtreeSum: subSums) {
            res = max(res, (total - subtreeSum) * subtreeSum);
        }
        return res;
    }
};