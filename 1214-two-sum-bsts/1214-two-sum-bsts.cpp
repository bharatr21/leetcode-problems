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
    void inOrder(TreeNode* root, vector<int>& vec) {
        if(!root) return;
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> vec1, vec2;
        inOrder(root1, vec1);
        inOrder(root2, vec2);
        int m = vec1.size(), n = vec2.size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0) {
            if(vec1[i] + vec2[j] == target) return true;
            else if(vec1[i] + vec2[j] < target) i++;
            else j--;
        }
        return false;
    }
};