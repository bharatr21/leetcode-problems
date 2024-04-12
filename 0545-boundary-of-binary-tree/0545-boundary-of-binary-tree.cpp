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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> result;
    boundary_of_binary_tree(root, result);
    return result;
}

    void boundary_of_binary_tree(const TreeNode* root, vector<int>& result, bool is_root = true, bool lb=false, bool rb=false) {
        if(root) {
            bool is_leaf = !root->left && !root->right;
            if(is_root || lb || is_leaf) {
                result.push_back(root->val);
            }
            boundary_of_binary_tree(root->left, result, false, is_root || lb, rb && !root->right);
            boundary_of_binary_tree(root->right, result, false, lb && !root->left, is_root || rb);
            if(rb && !is_leaf) {
                result.push_back(root->val);
            }
        } 
    }
};