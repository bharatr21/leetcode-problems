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
    bool markPath(string& path, TreeNode* root, int& value, bool up) {
        if(!root) return false;
        else if(root->val == value) return true;
        else {
            if(up) {
                path.push_back('U');
                if(markPath(path, root->left, value, up)) return true;
                if(markPath(path, root->right, value, up)) return true;
                path.pop_back();
            }
            else {
                path.push_back('L');
                if(markPath(path, root->left, value, up)) return true;
                path.pop_back();
                path.push_back('R');
                if(markPath(path, root->right, value, up)) return true;
                path.pop_back();
            }
            return false;
        }
    }

    TreeNode* lca(TreeNode* root, int startValue, int destValue) {
        if(!root) return NULL;
        if(root->val == startValue || root->val == destValue) return root;
        TreeNode* left = lca(root->left, startValue, destValue);
        TreeNode* right = lca(root->right, startValue, destValue);
        if(left && right) return root;
        else return ((left) ? left : right);
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string res;
        string src, dest;
        if(!root) return res;
        TreeNode* node = lca(root, startValue, destValue);
        markPath(src, node, startValue, true);
        markPath(dest, node, destValue, false);
        // cout << src << ' ' << dest << endl;
        res += (src + dest);
        return res;
    }
};