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
        ListNode* ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto list : lists) {
            while (list != NULL) {
                pq.push(list->val);
                list = list->next;
            }
        }
        if (pq.empty()) {
            return nullptr;
        }
        ListNode* temp;
        if (!pq.empty()) {
            ans = new ListNode(0);
            ans->val = pq.top();
            temp = ans;
            pq.pop();
        }
        while (!pq.empty()) {
            ListNode* temp1 = new ListNode(pq.top());
            pq.pop();
            temp->next = temp1;
            temp = temp1;
        }
        return ans;
    }
};