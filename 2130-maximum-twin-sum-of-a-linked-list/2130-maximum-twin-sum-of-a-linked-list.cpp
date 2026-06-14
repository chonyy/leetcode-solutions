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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* revHead = reverse(mid);

        int res = 0;
        while (head) {
            res = max(res, head->val + revHead->val);
            head = head->next;
            revHead = revHead->next;
        }

        return res;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prev;
        ListNode* next;

        while (node) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        return prev;
    }
};