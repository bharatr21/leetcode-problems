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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDel(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(-1), *cur = head, *prev = NULL;
        dummy->next = head;
        while(cur) {
            if(toDel.count(cur->val)) {
                if(dummy->next == cur) {
                    dummy->next = cur->next;
                } else {
                    prev->next = cur->next;
                }
            } else prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};