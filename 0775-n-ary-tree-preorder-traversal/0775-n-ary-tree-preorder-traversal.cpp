/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if(!root) return res;
        st.push(root);
        while(!st.empty()) {
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            reverse(node->children.begin(), node->children.end());
            for(Node* child: node->children) {
                st.push(child);
            }
        }
        return res;
    }
};