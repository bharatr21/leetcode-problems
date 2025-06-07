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
        Node *pp = p, *qq = q;
        vector<Node*> ppath, qpath;
        while(pp) {
            ppath.push_back(pp);
            pp = pp->parent;
        }
        while(qq) {
            qpath.push_back(qq);
            qq = qq->parent;
        }
        int m = ppath.size(), n = qpath.size();
        int i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0 && ppath[i] == qpath[j]) {
            i--;
            j--;
        }
        return qpath[j+1];
    }
};