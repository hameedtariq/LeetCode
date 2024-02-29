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
    typedef ListNode* ln;
public:
    bool isPalindrome(ListNode* head) {
        int n = getLen(head);
        int mid;
        ln p = head;
        if(n%2 == 0) {
            // even no. of nodes
            mid = n/2;            
        }else {
            // odd
            mid = ceil((float)n/2);
        }
        for(int i = 0; i<mid; i++){
            p = p->next;
        }
        ln x = reverseLink(p);
        // return 0;
        while(x && head) {
            if(x->val != head->val) return false; 
            x = x->next;
            head = head->next;
        }
        return true;
    }
    int getLen(ln p) {
        int k = 0;
        while(p) {
            k++;
            p = p->next;
        }
        return k;
    }
    ln reverseLink(ln p) {
        if(!p || !p->next) return p;
        ln prev = p;
        ln curr = p->next;
        while(curr) {
            ln temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        p->next = nullptr;
        return prev;
    }
};