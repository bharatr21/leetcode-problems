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
    int gcd(int a, int b) {
        return __gcd(a, b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *cur = head, *next = NULL;
        dummy->next = head;
        if(!cur) return head;
        next = cur->next;
        while(cur && next) {
            ListNode* tmp = new ListNode(gcd(cur->val, next->val));
            cur->next = tmp;
            tmp->next = next;
            cur = next;
            next = next->next;
        } 
        return dummy->next;
    }
};