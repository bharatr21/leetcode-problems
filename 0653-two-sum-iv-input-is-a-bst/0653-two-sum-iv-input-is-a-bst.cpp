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
    void inOrder(vector<int>& inorder, TreeNode* node) {
        if(!node) return;
        inOrder(inorder, node->left);
        inorder.push_back(node->val);
        inOrder(inorder, node->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inOrder(inorder, root);
        int n = inorder.size();
        int left = 0, right = n - 1;
        while(left < right) {
            int cur_sum = inorder[left] + inorder[right];
            if(cur_sum == k) return true;
            else if(cur_sum > k) right--;
            else left++;
        }
        return false;
    }
};