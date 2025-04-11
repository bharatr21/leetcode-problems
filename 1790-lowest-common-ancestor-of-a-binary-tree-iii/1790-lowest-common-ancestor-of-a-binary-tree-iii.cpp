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
        Node *tp = p, *tq = q;
        while(tp) {
            ppath.push_back(tp);
            tp = tp->parent;
        }
        while(tq) {
            qpath.push_back(tq);
            tq = tq->parent;
        }
        int m = ppath.size(), n = qpath.size();
        int i = 0, j = 0;
        while(ppath[i] != qpath[j] && i < m && j < n) {
            if(m - i > n - j) i++;
            else j++;
        }
        return ppath[i];
    }
};