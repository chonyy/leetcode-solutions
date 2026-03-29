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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sent = new ListNode();
        sent->next = head;
        ListNode* prev = sent;

        while (head) {
            int same = 0;
            while (head->next != nullptr && head->val == head->next->val) {
                head = head->next;
                same ++;
            }

            if (same > 0) {
                prev->next = head->next;
                head = head->next;
            }
            else {
                prev->next = head;
                prev = head;
                head = head->next;
            }
        }

        return sent->next;
    }
};