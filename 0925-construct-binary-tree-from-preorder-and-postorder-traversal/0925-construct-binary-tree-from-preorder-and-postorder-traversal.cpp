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
    TreeNode* buildTree(int preStart, int preEnd, int postStart, vector<int>& preorder, vector<int>& indexInPost) {
        if(preStart > preEnd) return NULL;
        else if(preStart == preEnd) return new TreeNode(preorder[preStart]);
        TreeNode* root = new TreeNode(preorder[preStart]);
        int leftRoot = preorder[preStart + 1];
        int num_left = indexInPost[leftRoot] - postStart + 1;
        root->left = buildTree(preStart + 1, preStart + num_left, postStart, preorder, indexInPost);
        root->right = buildTree(preStart + num_left + 1, preEnd, postStart + num_left, preorder, indexInPost);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        vector<int> indexInPost(n+1);
        for(int i = 0; i < n; i++) {
            indexInPost[postorder[i]] = i;
        }
        return buildTree(0, n - 1, 0, preorder, indexInPost);
    }
};