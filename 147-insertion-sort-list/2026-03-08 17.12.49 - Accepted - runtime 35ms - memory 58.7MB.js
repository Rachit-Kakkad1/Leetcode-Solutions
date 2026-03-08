/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function ListNode(val, next = null) {
    this.val = val;
    this.next = next;
}

var insertionSortList = function(head) {
    let dummy = new ListNode(0);
    let curr = head;

    while (curr) {
        let prev = dummy;
        let nextNode = curr.next;

        while (prev.next && prev.next.val < curr.val) {
            prev = prev.next;
        }

        curr.next = prev.next;
        prev.next = curr;

        curr = nextNode;
    }

    return dummy.next;
};