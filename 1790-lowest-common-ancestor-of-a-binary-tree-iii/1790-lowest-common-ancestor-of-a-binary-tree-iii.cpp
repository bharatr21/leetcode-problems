/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> ppath, qpath;
        while(p) {
            ppath.push_back(p);
            p = p->parent;
        }
        while(q) {
            qpath.push_back(q);
            q = q->parent;
        }
        int m = ppath.size(), n = qpath.size();
        int i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0 && ppath[i] == qpath[j]) {
            i--;
            j--;
        }
        return ppath[i+1];
    }
};