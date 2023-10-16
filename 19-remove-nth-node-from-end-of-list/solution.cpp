// Solution for 19. https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
        int tot = 0;
        ListNode *temp = head;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        while(temp)
        {
            tot++;
            temp = temp->next;
        }
        temp = dummy;
        int ct = tot - n;
        while(temp && ct)
        {
            ct--;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return dummy->next;
    }
};