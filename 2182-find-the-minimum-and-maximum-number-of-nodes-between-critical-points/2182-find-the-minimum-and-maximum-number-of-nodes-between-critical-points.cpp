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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> cp;
        ListNode *prev = NULL, *next = NULL, *cur = head;
        int idx = 0;
        while(cur) {
            next = cur->next;
            if(prev && next) {
                if((prev->val < cur->val && next->val < cur->val) || 
                (prev->val > cur->val && next->val > cur->val)) cp.push_back(idx);
            }
            prev = cur;
            cur = cur->next;
            idx++;
        }
        int n = cp.size(), i;
        if(n < 2) return {-1, -1};
        int mind = idx+1;
        for(i = 1; i < n; i++) {
            mind = min(mind, cp[i] - cp[i-1]);
        }
        return {mind, cp[n-1] - cp[0]};
    }
};