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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* res;
        ListNode* head;
        if(l1->val > l2->val) {
            res = l2;
            head = l2;
            l2 = l2->next;
        }else {
            res = l1;
            head = l1;
            l1 = l1->next;
        }
        while(l1 && l2) {
            if(l1->val > l2->val) {
                res->next = l2;
                l2 = l2->next;
            }else {
                res->next = l1;
                l1 = l1->next;
            }
            res = res->next;
        }
        while(l1){
            res->next = l1;
            l1 = l1->next;
            res = res->next;
        }
        while(l2) {
            res->next = l2;
            l2 = l2->next;
            res = res->next;
        }
        return head;
    }
};