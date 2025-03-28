/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function numComponents(head: ListNode | null, nums: number[]): number {
    if(!head) {
        return 0;
    }
    const set = new Set(nums);
    let n = 0;
    while(head) {
        if (set.has(head.val)) {
            while(head && set.has(head.val)) {
                head = head.next; // skip parts of connected components
                continue;
            }
            n++;
        }
        if (head) head = head.next;
    }
    return n;
};