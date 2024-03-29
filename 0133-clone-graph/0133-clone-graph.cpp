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
    void dfs(Node* node, unordered_map<Node*, Node*>& vis) {
        Node* clone = new Node(node->val);
        vis[node] = clone;
        for(auto neighbor: node->neighbors)
        {
            if(vis.find(neighbor) != vis.end())
            {
                clone->neighbors.push_back(vis[neighbor]);
            }
            else
            {
                dfs(neighbor, vis);
                clone->neighbors.push_back(vis[neighbor]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> vis;
        dfs(node, vis);
        return vis[node];
    }
};