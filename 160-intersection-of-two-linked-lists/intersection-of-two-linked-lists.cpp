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
        int s1 = 1, s2 = 1;
        auto p = headA;
        while(p->next) {
            p = p->next;
            s1++;        
        }
        auto q = headB;
        while(q->next) {
            q = q->next;
            s2++;        
        }

        if(p != q) return nullptr;

        p = headA, q= headB;
        while(p && q) {
            if(p == q) return p;
            if(s1 > s2) {
                s1--;
                cout << "P: " <<p->val << endl;
                p = p->next;
            }else {
                s2--;
                cout << "Q: " << q->val << endl;
                q = q->next;
            }
        }

        return nullptr;
    }
};