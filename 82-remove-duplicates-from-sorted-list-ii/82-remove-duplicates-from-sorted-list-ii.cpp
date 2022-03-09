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
        ListNode* sentinel = new ListNode(0);
        ListNode* resHead = sentinel;
        ListNode* cur = head;
        
        while(cur) {
            bool same = false;
            
            while(cur && cur->next) {
                if(cur->val != cur->next->val) {
                    break;
                }
                
                same = true;
                cur = cur->next;
            }
            
            if(!same) {
                resHead->next = cur;
                resHead = resHead->next;
            }
            
            if(cur)
                cur = cur->next;
        }
        
        resHead->next = nullptr;
        return sentinel->next;
    }
};