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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3;
        ListNode* head = new ListNode(-1);
        l3 = head;
        int sum = 0, carry = 0;
        while(l1 || l2 || carry > 0) {
            sum = 0;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            l3->next = new ListNode(sum);
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            l3 = l3->next;
        }
        return head->next;
    }
};