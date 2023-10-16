// Solution for 206. https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head, *prev = NULL, *next = NULL;
        while(temp)
        {
            //Iteratively adjust 1->2 to 2->1 in this step, 
            // moving temp forward by one at the end of each iteration
            next = temp -> next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
};