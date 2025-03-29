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
    vector<int> getList(ListNode* head) {
        vector<int> res;
        ListNode* tmp = head;
        while(tmp) {
            res.push_back(tmp->val);
            tmp = tmp->next;
        }
        return res;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* res;
        vector<int> v = getList(head);
        int sz = v.size();
        if(sz == 0) return res;
        k = k % sz;
        vector<int> tmp(sz);
        for(int i = 0; i < sz; i++) {
            tmp[i] = v[(i - k + sz) % sz];
        }
        res = new ListNode(tmp[0]);
        ListNode* node = res;
        int i = 1;
        while(i < sz) {
            node->next = new ListNode(tmp[i++]);
            node = node->next;
        }
        return res;
    }
};