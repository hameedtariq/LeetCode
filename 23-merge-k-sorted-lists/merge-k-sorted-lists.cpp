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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if(left == right) return lists[left];
        
        int mid = left + (right-left)/2;
        auto x = merge(lists, left, mid);
        auto y = merge(lists, mid+1, right);

        auto dummy = new ListNode();
        auto curr = dummy;
        while(x && y) {
            if(x->val <= y->val) {
                curr->next = x;
                x = x->next;
            }else {
                curr->next = y;
                y = y->next;
            }
            curr = curr->next;
        }
        if(x) {
            curr->next = x;
        }
        if(y) {
            curr->next = y;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};