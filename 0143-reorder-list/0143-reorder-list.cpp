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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *next = nullptr;
        ListNode* cur = head;
        
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    void merge(ListNode* l1, ListNode* l2) {
        while(l2) {
            ListNode* next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next; 
        }
            
    }
    
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        auto mid = slow->next;
        slow->next = nullptr;
        
        auto revHead = reverse(mid);
        
        merge(head, revHead);
    }
};