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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* sent = new ListNode(-1000);
        sent->next = head;

        ListNode* prevLeft = sent;
        ListNode* leftNode = head;

        for (int i = 1; i < left; i ++) {
            leftNode = leftNode->next;
            prevLeft = prevLeft->next;
        }

        ListNode* rightNode = head;
        for (int i = 1; i < right; i ++) {
            rightNode = rightNode->next;
        }
        ListNode* nextRight = rightNode->next;

        // cut
        prevLeft->next = nullptr;
        rightNode->next = nullptr;

        ListNode* revHead = reverse(leftNode);
        prevLeft->next = revHead;
        leftNode->next = nextRight;

        return sent->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* cur = head;

        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};