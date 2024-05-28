/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    typedef ListNode Node;
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        while(node->next) {
            node->val = node->next->val;
            if(!node->next->next){
                delete node->next;
                node->next = nullptr;
                break;
            }
            node = node->next;
        }
    }
};