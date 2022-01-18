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
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        unordered_map<Node*,Node*> m;
        Node* sentinel = new Node(0);
        Node* newHead = sentinel;
        m[nullptr] = nullptr;
        
        while(cur) {
            Node* newNode = new Node(cur->val);
            newHead->next = newNode;
            
            m[cur] = newNode;
            newHead = newHead->next;
            cur = cur->next;
        }
        
        cur = head;
        newHead = sentinel->next;
        while(cur) {
            auto newRandom = m[cur->random];
            newHead->random = newRandom;
            
            newHead = newHead->next;
            cur = cur->next;
        }
        
        return sentinel->next;
    }
};