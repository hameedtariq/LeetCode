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
        ListNode* prev = nullptr;
        while(p && p->next) {
            // does duplicate exist?
            if(p->val == p->next->val) {
                while(p && p->next && p->val == p->next->val) { // for duplicates
                    auto temp = p->next->next;
                    delete p->next;
                    p->next = temp;
                }
                if(p){
                    auto temp = p->next;
                    delete p;
                    p = temp;
                    if(prev) { // not head
                        prev->next = p;
                    }else {
                        head = p;
                    }
                }
            }else {
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};