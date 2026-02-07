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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* sent = new ListNode();
        ListNode* cur = sent;

        while (l1 || l2) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;

            int res = num1 + num2 + carry;
            carry = res / 10;
            res = res % 10;
            cur->next = new ListNode(res);
            cur = cur->next;

            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }
        }

        if (carry) {
            cur->next = new ListNode(1);
        }

        return sent->next;
    }
};