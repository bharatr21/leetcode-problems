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
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<pair<Node*, int>> st;
        Node* curr = NULL;
        curr = root;
        while(curr != NULL || st.size()){
            if(curr == NULL){
                auto parent = st.top().first;
                auto childNum = st.top().second;
                curr = parent -> children[childNum];
                st.pop();
                if(childNum > 0 ){
                    st.push({parent, childNum-1});
                }
            } else{
                res.push_back(curr -> val);
                if(curr -> children.size() > 1){
                    st.push({curr, curr -> children.size()-2});
                }
                curr = curr -> children.size() ?
                 curr -> children[curr -> children.size()-1] : NULL;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};