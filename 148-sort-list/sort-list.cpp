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

 bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Split the linked list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr; // Break the list into two parts

        // Recursively split & sort the sublists
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge the sorted sublists
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Create a dummy node
        ListNode* current = dummy.next = &dummy; // Start from the dummy node

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Attach the remaining elements, if any
        if (l1) current->next = l1;
        if (l2) current->next = l2;

        return dummy.next;
    }
};
