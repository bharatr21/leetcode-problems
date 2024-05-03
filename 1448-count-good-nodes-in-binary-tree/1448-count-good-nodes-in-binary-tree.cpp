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
    int goodNodes(TreeNode* root) {
       int good = 0, mx = -10001;
       if(!root) return 0;
       queue<pair<TreeNode*, int>> q;
       q.push({root, root->val});
       while(!q.empty())
       {
            auto [node, mx] = q.front();
            q.pop();
            if(node->val >= mx) 
            {
                mx = node->val;
                good++;
            }
            if(node->left) q.push({node->left, mx});
            if(node->right) q.push({node->right, mx});
       }
       return good;
    }
};