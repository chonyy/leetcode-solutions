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
    ListNode* temp;
    
    Solution(ListNode* head) {
        temp = head;
    }
    
    int getRandom() {
        ListNode* cur = temp;
        int res = 0;
        int size = 1;
        
        while(cur) {
            if(rand() % size == 0) {
                res = cur->val;
            }
            
            size ++;
            cur = cur->next;
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */