/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* temp = head;
        Node* head2 = new Node(head->val);
        Node* temp2 = head2;
        unordered_map<Node*, Node*> mp;
        mp[head] = head2;
        while(temp) {
            if(temp->random) {
                if(mp.count(temp->random)) {
                    temp2->random = mp[temp->random];
                } else {
                    Node* rand = new Node(temp->random->val);
                    temp2->random = rand;
                    mp[temp->random] = rand;
                }
            } else {
                temp2->random = NULL;
            }
            if(temp->next) {
                if(mp.count(temp->next)) {
                    temp2->next = mp[temp->next];
                } else {
                    Node* next = new Node(temp->next->val);
                    temp2->next = next;
                    mp[temp->next] = next;
                }
            } else {
                temp2->next = NULL;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return head2;
    }
};