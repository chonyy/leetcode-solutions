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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        ListNode* revHead = reverse(mid);

        merge(head, revHead);
    }

    void merge(ListNode* head, ListNode* revHead) {
        ListNode* sent = new ListNode();

        while (head && revHead) {
            // cout << head->val << " " << revHead->val << endl;
            ListNode* nextHead = head->next;
            ListNode* nextRevHead = revHead->next;

            sent->next = head;
            sent->next->next = revHead;

            head = nextHead;
            revHead = nextRevHead;
            sent = sent->next->next;
        }

        if (head) {
            sent->next = head;
        }

        if (revHead) {
            sent->next = revHead;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};