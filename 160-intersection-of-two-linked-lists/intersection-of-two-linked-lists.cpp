/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA;
        auto q = headB;
        // Traverse both lists, switching pointers to the other list's head when reaching the end
        while (p != q) {
            p = p ? p->next : headB;  // Move p, or reset to headB if at the end of list A
            q = q ? q->next : headA;  // Move q, or reset to headA if at the end of list B
        }
        return p;
    }
};