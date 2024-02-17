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
        if(k==0 || head==NULL) return head;
// Check if list has sufficient length (atleast count = k) then only proceed
        int count = 0;
        ListNode* check = head;
        while(check!=NULL && count < k) {
            count++;
            check=check->next;
        }
        if(count<k) return head;
        
    // Reverse start    
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* fwd;
        count = 0;
        while(cur!=NULL && count < k)
        {
            fwd = cur->next;
            cur->next = prev;
            prev = cur;
            cur = fwd;
            count++;
        }
        if(fwd!=NULL)
        {
            head->next = reverseKGroup(fwd, k);
        }
        return prev;
        
    }
};