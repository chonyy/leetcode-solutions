/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> copy;

    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        if (copy.contains(head)) {
            return copy[head];
        }

        Node* node = new Node(head->val);
        copy[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }
};