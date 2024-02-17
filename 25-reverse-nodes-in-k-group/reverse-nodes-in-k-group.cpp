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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        auto l = head;
        auto r = getRight(l, k);
        if(!r) return l;
        auto curr = l->next;
        auto prev = l;
        while(curr != r) {
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        l->next = reverseKGroup(r->next, k);
        r->next = prev;
        return r;
    }
    ListNode* getRight(ListNode* p, int k) {
        int x = 0;
        while(p){
            x++;
            if(x == k) break;
            p = p->next;
        }
        return p;
    }

};