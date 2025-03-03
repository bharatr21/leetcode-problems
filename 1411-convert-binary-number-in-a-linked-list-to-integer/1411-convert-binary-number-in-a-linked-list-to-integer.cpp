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
    int getDecimalValue(ListNode* head) {
        vector<bool> v;
        ListNode* node = head;
        while(node) {
            v.push_back(node->val);
            node = node->next;
        }
        int n = v.size(), pow = 1, res = 0;
        for(int i = n - 1; i >= 0; i--) {
            res += v[i] * pow;
            pow <<= 1;
        }
        return res;
    }
};