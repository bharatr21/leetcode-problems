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
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        int n = lists.size();
        bool change = true;
        while(change) {
            change = false;
            int mn = 10001, minIdx = -1;
            for(int i = 0; i < n; i++) {
                if(lists[i] && lists[i]->val < mn) {
                    mn = lists[i]->val;
                    minIdx = i;
                }
            }
            if(minIdx != -1) {
                res->next = new ListNode(lists[minIdx]->val);
                res = res->next;
                if(lists[minIdx]) {
                    lists[minIdx] = lists[minIdx]->next;
                    change = true;
                }
            }
        }
        return dummy->next;
    }
};