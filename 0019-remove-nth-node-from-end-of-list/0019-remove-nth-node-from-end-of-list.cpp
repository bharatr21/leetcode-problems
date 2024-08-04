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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slo = head, *prev = NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int ct = 1;
        while(ct <= n && fast) {
            fast = fast->next;
            ct++;
        }
        while(fast) {
            fast = fast->next;
            prev = slo;
            slo = slo->next;
        }
        if(slo == head && !prev) dummy->next = slo->next;
        else if(slo) prev->next = slo->next;
        else prev->next = NULL;
        return dummy->next;
    }
};