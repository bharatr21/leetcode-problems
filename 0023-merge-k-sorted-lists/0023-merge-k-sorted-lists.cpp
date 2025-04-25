/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int ptr = -1;
        int k = lists.size();
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        if(k == 0) return nullptr;
        bool changed = true;
        int mn = 10000;
        while(mn < 10001) {
            mn = 10001;
            for(int i = 0; i < k; i++) {
                if(lists[i] && mn > lists[i]->val) {
                    mn = lists[i]->val;
                    ptr = i;
                }
            }
            if(mn < 10001) {
                node->next = new ListNode(mn);
                node = node->next;
                if(ptr != -1 && lists[ptr]) lists[ptr] = lists[ptr]->next;
            }
        }
        return head->next;
    }
};