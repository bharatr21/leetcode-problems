/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        stack<Node*> st;
        while(cur) {
            if(cur->child) {
                Node* next = cur->next;
                if(next) st.push(next);
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
            }
            if(!cur->next && !st.empty()) {
                cur->next = st.top();
                cur->next->prev = cur;
                st.pop();
            }
            cur = cur->next;
        }
        return head;
    }
};