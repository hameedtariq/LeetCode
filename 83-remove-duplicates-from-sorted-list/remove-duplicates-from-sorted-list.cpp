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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        auto p = head;
        while(p) {
            auto curr = p->next;
            while(curr && curr->val == p->val ) { // for duplicates
                auto temp = curr->next;
                delete curr;
                curr = temp;
            }
            p->next = curr;
            p = p->next;
        }
        return head;
    }
};