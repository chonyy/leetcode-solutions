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
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* cur;
        stack<ListNode*> stk;
        
        while(head) {
            while(!stk.empty() && stk.top()->val < head->val) {
                stk.pop();
            }
            
            if(stk.empty()) {
                cur = newHead;
            }
            else {
                cur = stk.top();
            }
            cur->next = head;
            stk.push(head);
            
            head = head->next;
        }
        
        return newHead->next;
    }
};