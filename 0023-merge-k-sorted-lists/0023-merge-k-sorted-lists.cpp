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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* n1, ListNode* n2) {
            return n1->val > n2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* node : lists) {
            if (node) {
                pq.push(node);
            }
        }

        ListNode* sent = new ListNode();
        ListNode* cur = sent;

        while (!pq.empty()) {
            ListNode* small = pq.top();
            pq.pop();
            
            cur->next = small;

            if (small->next) {
                pq.push(small->next);
            }

            cur = cur->next;
        }

        return sent->next;
    }
};