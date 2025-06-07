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
    bool isLeaf(TreeNode* root) {
        return root && !root->left && !root->right;
    }

    int b2i(string s) {
        int res = 0;
        int n = s.size();
        int tmp = 1;
        for(int i = n - 1; i >= 0; i--) {
            res += (s[i] - '0') * tmp;
            tmp = tmp << 1;
        }
        return res;
    }

    void collect(TreeNode* root, string tmp, vector<string>& res) {
        tmp += (root->val + '0');
        if(isLeaf(root)) {
            res.push_back(tmp);
            return;
        }
        if(root->left) collect(root->left, tmp, res);
        if(root->right) collect(root->right, tmp, res);
    }

    int sumRootToLeaf(TreeNode* root) {
        string tmp;
        int res = 0;
        vector<string> bins;
        if(!root) return 0;
        collect(root, tmp, bins);
        for(string num: bins) {
            res += b2i(num);
        }
        return res;
    }
};