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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next) {
            return {-1, -1};
        }
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* next = cur-> next;
        
        int maxDist = INT_MIN;
        int minDist = INT_MAX;
        
        int i = 1;
        int firstCrit = 0;
        int prevCrit = 0;
        
        while(next) {
            if(isCrit(prev->val, cur->val, next->val)) {
                if(firstCrit) {
                    maxDist = i - firstCrit;
                    minDist = min(minDist, i - prevCrit);
                }
                else {
                    firstCrit = i;
                }
                
                prevCrit = i;
            }
            
            
            prev = cur;
            cur = cur->next;
            next = next->next;
            
            i ++;
        }
        
        if(minDist == INT_MAX) {
            minDist = -1;
        }
        if(maxDist == INT_MIN) {
            maxDist = -1;
        }
        
        return {minDist, maxDist};
    }
    
    bool isCrit(int prev, int cur, int next) {
        if(prev < cur && cur > next) {
            return true;
        }
        else if(prev > cur && cur < next) {
            return true;
        }
        
        return false;
    }
};