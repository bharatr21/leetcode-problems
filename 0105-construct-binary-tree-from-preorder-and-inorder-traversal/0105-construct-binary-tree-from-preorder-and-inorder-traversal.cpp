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
    int pre = 0;
    // int findIndex(vector<int>& inorder, int st, int en, int num)
    // {
    //     int n = inorder.size(), i;
    //     for(i = st; i <= en; i++) {
    //         if(inorder[i] == num) return i;
    //     }
    //     return -1;
    // }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inMap, int st, int en) {
        if(st > en) return NULL;
        int val = preorder[pre++];
        TreeNode* root = new TreeNode(val);
        int idx = inMap[val];
        root->left = build(preorder, inMap, st, idx - 1);
        root->right = build(preorder, inMap, idx + 1, en);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        TreeNode* root = NULL;
        int n = inorder.size();
        for(int i = 0; i < n; i++) inMap[inorder[i]] = i;
        return build(preorder, inMap, 0, n - 1);
    }
};