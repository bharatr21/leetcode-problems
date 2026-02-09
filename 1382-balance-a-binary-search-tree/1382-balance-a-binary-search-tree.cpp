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
    void inOrder(TreeNode* root, vector<int>& res) {
        if(!root) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    TreeNode* createBST(vector<int>& res, int start, int end) {
        if(start > end) return NULL;
        else if(start == end) return new TreeNode(res[start]);
        else {
            int mid = start + (end - start) / 2;
            TreeNode* root = new TreeNode(res[mid]);
            root->left = createBST(res, start, mid - 1);
            root->right = createBST(res, mid + 1, end);
            return root;
        }
        
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        int n = res.size();
        return createBST(res, 0, n - 1);
    }
};