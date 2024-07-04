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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *l1 = head, *res = new ListNode();
        ListNode *dummy = res;
        int sum = 0;
        while(l1) {
            if(l1->val == 0) {
                res->val = sum;
                if(l1->next) res->next = new ListNode();
                res = res->next;
                sum = 0;
            }
            else sum += l1->val;
            l1 = l1->next;
        }
        return dummy->next;
    }
};