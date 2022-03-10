
using namespace std;

// Struct ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this struct.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    
public:
    ListNode* addTwoNumbers(ListNode* headOne, ListNode* headTwo) {
        ListNode* dummyNode = new ListNode();
        ListNode * current{ dummyNode};
        int carryOverDigit = 0;

        while (headOne != nullptr || headTwo != nullptr) {
            int first = (headOne != nullptr) ? headOne->val : 0;
            int second = (headTwo != nullptr) ? headTwo->val : 0;

            int sum = first + second + carryOverDigit;
            carryOverDigit = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            headOne = (headOne != nullptr) ? headOne->next : nullptr;
            headTwo = (headTwo != nullptr) ? headTwo->next : nullptr;
        }

        if (carryOverDigit > 0) {
            current->next = new ListNode(carryOverDigit);
        }
        return dummyNode->next;
    }
};
