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
    void reorderList(ListNode* head) {
        // Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse 2nd half
        ListNode *prev = nullptr, *cur = slow, *tmp; 
        while(cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        //Merge two sorted linked lists
        ListNode *first = head, *sec = prev;
        while(sec->next) {
            tmp = first->next;
            first->next = sec;
            first = tmp;
            tmp = sec->next;
            sec->next = first;
            sec = tmp;
        }
    }
};