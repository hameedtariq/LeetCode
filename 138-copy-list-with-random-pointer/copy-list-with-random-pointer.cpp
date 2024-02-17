/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* newHead = nullptr;
        Node* t1 = head;
        Node* t2 = newHead;
        while(t1) {
            if(!newHead) {
                newHead = new Node(t1->val);
                t2 = newHead;
            }else {
                t2->next = new Node(t1->val);
                t2 = t2->next;
            }
            m[t1] = t2;
            t1 = t1->next;
        }
        t1 = head;
        t2 = newHead;
        while(t1) {
            t2->random = m[t1->random];
            t1 = t1->next;
            t2 = t2->next;
        }
        return newHead;        
    }
};