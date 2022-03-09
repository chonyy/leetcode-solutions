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
            
            // skip all the same num, set the flag to true if there's any same
            while(cur && cur->next) {
                if(cur->val != cur->next->val) {
                    break;
                }
                same = true;
                cur = cur->next;
            }
            
            // append to result if there's no same
            if(!same) {
                resHead->next = cur;
                resHead = resHead->next;
            }
            
            // no matter there's same or not, we always want to advance one
            cur = cur->next;
        }
        
        // make sure the we are pointing to NULL at last
        resHead->next = nullptr;
        return sentinel->next;
    }
};