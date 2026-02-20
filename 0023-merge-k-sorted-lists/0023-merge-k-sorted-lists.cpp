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
        if(lists.empty()) return nullptr;
        ListNode* head = new ListNode(0);
        ListNode* res = head;
        int k = lists.size(), idx = 0, mn = 10000;
        while(mn < 10001) {
            mn = 10001;
            for(int i = 0; i < k; i++) {
                if(lists[i] && lists[i]->val < mn) {
                    mn = lists[i]->val;
                    idx = i;
                }
            }
            if(mn < 10001) {
                res->next = new ListNode(mn);
                res = res->next;
                if(lists[idx]) lists[idx] = lists[idx]->next;
            }
        }
        return head->next;
    }
};