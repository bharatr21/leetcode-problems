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
class BSTIterator {
public:
    vector<int> elements;
    int ptr;
    BSTIterator(TreeNode* root) {
        inOrder(root, elements);
        ptr = 0;
    }

    void inOrder(TreeNode* root, vector<int>& elements) {
        if(!root) return;
        inOrder(root->left, elements);
        elements.push_back(root->val);
        inOrder(root->right, elements);
    }
    
    int next() {
        return elements[ptr++];
    }
    
    bool hasNext() {
        return (ptr < elements.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */