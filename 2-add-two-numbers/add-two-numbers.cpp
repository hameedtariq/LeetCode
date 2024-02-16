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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* head = nullptr;

        int carry = 0;
        while(l1 && l2) {
            int t = l2->val + l1->val + carry;
            carry = t / 10;
            if(!res){ 
                res = new ListNode(t%10);
                head = res;
            }
            else {
                res->next = new ListNode(t%10);
                res = res->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int t = l1->val + carry;
            carry = t / 10;
            res->next = new ListNode(t%10);
            res = res->next;
            l1 = l1->next;
        }
        while(l2) {
            int t = l2->val + carry;
            carry = t / 10;
            res->next = new ListNode(t%10);
            res = res->next;
            l2 = l2->next;
        }
        if(carry != 0) {
            res->next = new ListNode(carry);
            res = res->next;
        }
        return head;
    }
};