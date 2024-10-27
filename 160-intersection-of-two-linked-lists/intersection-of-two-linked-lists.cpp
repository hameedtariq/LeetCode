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
        unordered_set<ListNode*> m;
        auto p = headA;
        while(p) {
            m.insert(p);
            p = p->next;        
        }
        p = headB;
        while(p) {
            if(m.find(p) == m.end()) p = p->next;
            else return p;
        }

        return nullptr;
    }
};