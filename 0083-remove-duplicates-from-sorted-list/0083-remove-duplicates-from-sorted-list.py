# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return None
        seen = set()
        dummy = ListNode(-101)
        dummy.next = head
        prev, node = dummy, head
        while node:
            nex = node.next
            if node.val in seen:
                prev.next = nex
                tmp = node
                node = nex
                del tmp
            else:
                seen.add(node.val)
                prev = node
                node = nex
        return dummy.next
            



