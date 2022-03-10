
// Function ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this function.
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} headOne
 * @param {ListNode} headTwo
 * @return {ListNode}
 */
var addTwoNumbers = function (headOne, headTwo) {

    const dummyNode = new ListNode();
    let current = dummyNode;
    let carryOverDigit = 0;

    while (headOne !== null || headTwo !== null) {
        let first = (headOne !== null) ? headOne.val : 0;
        let second = (headTwo !== null) ? headTwo.val : 0;

        let sum = first + second + carryOverDigit;
        carryOverDigit = Math.floor(sum / 10);

        current.next = new ListNode(sum % 10);
        current = current.next;

        headOne = (headOne !== null) ? headOne.next : null;
        headTwo = (headTwo !== null) ? headTwo.next : null;
    }

    if (carryOverDigit > 0) {
        current.next = new ListNode(carryOverDigit);
    }
    return dummyNode.next;
};
