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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> store;
        unordered_map<int, bool> hasParent;
        for(auto v: descriptions) {
            int parent = v[0], child = v[1], isLeft = v[2]; 
            if(store.find(parent) == store.end()) {
                store[parent] = new TreeNode(parent);
            }
            if(store.find(child) == store.end()) {
                store[child] = new TreeNode(child);
            }
            TreeNode* node = store[parent];
            TreeNode* childnode = store[child];
            if(isLeft) {
                node->left = childnode;
            }
            else {
                node->right = childnode;
            }
            if(hasParent.find(parent) == hasParent.end()) hasParent[parent] = 0;
            hasParent[child] = true;
        }

        for(auto u: hasParent) {
            if(!u.second) {
                return store[u.first];
            }
        }
        return NULL;
    }
};