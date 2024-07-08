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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> freq;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *node = head, *prev = dummy, *cur = head;
        while(node)
        {
            freq[node->val]++;
            node = node->next;
        }
        node = head;
        while(cur)
        {
            if(freq[cur->val] >= 2)
                prev->next = cur->next;
            else prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};