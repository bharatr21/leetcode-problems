/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void helper(Node* node, unordered_map<Node*, Node*>& vis) {
        if(!node || vis.count(node)) return;
        Node* tmp = new Node(node->val);
        vis[node] = tmp;
        for(Node* neigh: node->neighbors) {
            helper(neigh, vis);
            tmp->neighbors.push_back(vis[neigh]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> vis;
        helper(node, vis);
        return vis[node];
    }
};