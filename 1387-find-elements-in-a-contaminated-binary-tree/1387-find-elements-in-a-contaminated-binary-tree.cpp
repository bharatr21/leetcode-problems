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
class FindElements {
public:
    unordered_set<int> s;

    void helper(TreeNode* root, int x) {
        if(!root) return;
        else if(root->val == -1) {
            root->val = x;
            s.insert(x);
        }
        helper(root->left, 2 * x + 1);
        helper(root->right, 2 * x + 2);
    }

    FindElements(TreeNode* root) {
       if(!root) return;
       helper(root, 0);
    }
    
    bool find(int target) {
        return (s.count(target) > 0);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */