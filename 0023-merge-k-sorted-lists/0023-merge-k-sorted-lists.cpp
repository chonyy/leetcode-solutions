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
        int n = lists.size();
        int increase = 1;

        if (n == 0) return nullptr;

        while (increase < n) {
            for (int i = 0; i < n; i += 2 * increase) {
                if (i + increase >= n) {
                    continue;
                }

                ListNode* first = lists[i];
                ListNode* second = lists[i + increase];

                ListNode* merged = merge(first, second);

                lists[i] = merged;
            }

            increase = increase * 2;
        }

        return lists[0];
    }

    ListNode* merge(ListNode* n1, ListNode* n2) {
        ListNode* sent = new ListNode();
        ListNode* cur = sent;

        while (n1 && n2) {
            if (n1->val <= n2->val) {
                cur->next = n1;
                n1 = n1->next;
            }
            else {
                cur->next = n2;
                n2 = n2->next;
            }

            cur = cur->next;
        }

        // append remain tail
        if (n1) {
            cur->next = n1;
        }
        if (n2) {
            cur->next = n2;
        }

        return sent->next;
    }
};