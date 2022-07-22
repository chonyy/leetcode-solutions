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
    ListNode* partition(ListNode* head, int x) {
        ListNode* largerHead = new ListNode(0);
        ListNode* larger = largerHead;
        ListNode* lessHead = new ListNode(0);
        ListNode* less = lessHead;

        while(head) {
            cout << head->val << endl;
            if(head->val < x) {
                less->next = head;
                less = less->next;
            }
            else {
                larger->next = head;
                larger = larger->next;
            }

            head = head->next;
        }

        larger->next = nullptr;
        less->next = largerHead->next;

        return lessHead->next;
    }
};