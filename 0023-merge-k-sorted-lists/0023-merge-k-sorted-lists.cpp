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
        if (lists.size() == 0) {
            return nullptr;
        }

        deque<ListNode*> dq;
        for(auto list : lists) {
            dq.push_back(list);
        }

        while (dq.size() > 1) {
            ListNode* first = dq.front();
            dq.pop_front();
            ListNode* second = dq.front();
            dq.pop_front();

            dq.push_back(merge(first, second));
        }

        return dq.front();
    }

    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode* sentinel = new ListNode(0);
        ListNode* cur = sentinel;

        while (first && second) {
            if (first->val < second->val) {
                cur->next = first;
                first = first->next;
            }
            else {
                cur->next= second;
                second = second->next;
            }

            cur = cur->next;
        }

        if (first) {
            cur->next = first;
        }

        if (second) {
            cur->next = second;
        }

        return sentinel->next;
    }
};