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
    unordered_map<int, int> m;
    int count = 0;
    
    Solution(ListNode* head) {
        while(head) {
            m[count] = head->val;
            
            count ++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int idx = rand() % count;
        return m[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */