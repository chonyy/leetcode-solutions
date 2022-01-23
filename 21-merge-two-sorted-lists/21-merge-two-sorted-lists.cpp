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
    // 1,2,4   3,4
    // 1
    
//     2,4  3,4
//     1->1
        
//     4  3,4
//     1->1->2    
    
//     4  4
//     1->1->2->3
       
//     4 null    
//     1->1->2->3->4
        
//     1->1->2->3->4->4
        
    // 1,2  null
    // 1,2
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* sentinel = new ListNode(0);
        ListNode* cur = sentinel;
        
        // Loop both list
        while(l1 && l2) {
            // Compare value
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        // Link the remain nodes
        if(l1) {
            cur->next = l1;
        }
        if(l2) {
            cur->next = l2;
        }
        
        return sentinel->next;
    }
};