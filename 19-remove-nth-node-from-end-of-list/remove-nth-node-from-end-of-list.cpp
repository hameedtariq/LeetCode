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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head;
        int size = 0;
        while(p) {size++; p = p->next;};
        if(n == size) return head->next;
        int i = 1;
        p = head;
        while(i < size - n) {
            i++;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};