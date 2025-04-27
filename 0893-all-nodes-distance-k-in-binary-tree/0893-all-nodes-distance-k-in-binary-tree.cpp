/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if(!root) return;
        if(root->left) {
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
            buildGraph(root->left, adj);
        }
        if(root->right) {
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            buildGraph(root->right, adj);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        vector<int> res;
        if(!root || !target) return res;
        buildGraph(root, adj);
        queue<pair<int, int>> q;
        unordered_set<int> seen;
        q.push({target->val, 0});
        while(!q.empty()) {
            auto [val, depth] = q.front();
            q.pop();
            if(depth > k) continue;
            if(depth == k) res.push_back(val);
            seen.insert(val);
            for(auto& neigh: adj[val]) {
                if(!seen.count(neigh)) q.push({neigh, depth+1});
            }
        }
        return res;
    }
};