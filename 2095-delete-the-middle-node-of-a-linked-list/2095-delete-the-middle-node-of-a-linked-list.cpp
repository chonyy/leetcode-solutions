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
    ListNode* deleteMiddle(ListNode* head) {
        int size = 0;
        
        if(!head)
            return head;
        
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            size ++;
        }
        
        size = size / 2 - 1;
        if(size < 0)
            return nullptr;
        cur = head;
        while(size --) {
            cur = cur->next;
        }
        
        if(cur->next)
            cur->next = cur->next->next;
        
        return head;
    }
};