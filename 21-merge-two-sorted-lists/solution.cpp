// Solution for 21. https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* l3 = head;
        while(list1 || list2)
        {
            if(list1 && list2)
            {
                if(list1->val <= list2->val)
                {
                    l3->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    l3->next = list2;
                    list2 = list2->next;
                }
                l3 = l3->next;
            }
            else if(list1)
            {
                l3->next = list1;
                list1 = list1->next;
                l3 = l3->next;
            }
            else if(list2)
            {
                l3->next = list2;
                list2 = list2->next;
                l3 = l3->next;
            }
        }
        return head->next;
    }
};