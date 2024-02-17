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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        if(left == right) return head;
        ListNode* l;
        ListNode* leftNode;
        ListNode* pl = head;
        int i = 1;
        // find left node
        while(i != left){
            i++;
            pl = pl->next;
        }
        leftNode = pl;
        l = pl->next;
        //find right node
        ListNode* r = pl;
        while(i != right){
            r = r->next;
            i++;
        }
        while(l != r) {
            auto temp = l->next;
            l->next = pl;
            pl = l;
            l = temp;
        }
        leftNode->next = r->next;
        l->next = pl;
        if(head == leftNode) {
            return r;
        }
        auto temp = head;
        while(temp->next != leftNode) temp = temp->next;
        temp->next = r;
        return head;
    }
};