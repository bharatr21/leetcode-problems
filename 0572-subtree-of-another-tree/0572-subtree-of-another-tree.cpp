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
    bool isSametree(TreeNode* p, TreeNode* q) {
        if(!p && q || p && !q) return false;
        if(!p && !q) return true;
        else return ((p->val == q->val) && isSametree(p->left, q->left) && isSametree(p->right, q->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot) return false;
        if(!subRoot) return true;
            return ((root->val == subRoot->val) && 
                isSametree(root->left, subRoot->left) && 
                isSametree(root->right, subRoot->right)) ||
                isSubtree(root->left, subRoot) || 
                isSubtree(root->right, subRoot);
    }
};
