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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sent = new ListNode();
        sent->next = head;
        ListNode* cur = head;
        ListNode* prev = sent;

        while (cur) {
            // find the end after size k. If can't, break
            ListNode* tail = cur;
            int move = k-1;
            while (tail && move) {
                tail = tail->next;
                move --;
            }
            if (!tail) {
                break;
            }
            // cut the tail
            // keep track of next
            // reverse the size-K list and return reversed head
            ListNode*next = tail->next;
            tail->next = nullptr;
            ListNode* revHead = reverse(cur);

            // prev->next = reversed head
            // prev = oldHead
            // revTail->next = next
            // cur = next

            prev->next = revHead;
            prev = cur;
            cur->next = next;
            cur = next;
        }

        return sent->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (cur) {
            next = cur->next;
            cur->next= prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};