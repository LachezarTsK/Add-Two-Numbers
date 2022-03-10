
public class Solution {

    public ListNode addTwoNumbers(ListNode headOne, ListNode headTwo) {
        
        ListNode dummyNode = new ListNode();
        ListNode current = dummyNode;
        int carryOverDigit = 0;
        
        while (headOne != null || headTwo != null) {
            int first = (headOne != null) ? headOne.val : 0;
            int second = (headTwo != null) ? headTwo.val : 0;
            
            int sum = first + second + carryOverDigit;
            carryOverDigit = sum / 10;
            
            current.next = new ListNode(sum % 10);
            current = current.next;
            
            headOne = (headOne != null) ? headOne.next : null;
            headTwo = (headTwo != null) ? headTwo.next : null;
        }
        
        if (carryOverDigit > 0) {
            current.next = new ListNode(carryOverDigit);
        }
        return dummyNode.next;
    }
}

// Class ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this class.
class ListNode {
    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
