/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        if(!head || !head->next)
            return false;
        ListNode* fast = head->next;
        
        while(fast->next && fast->next->next) {
            if(fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return false;
    }
};