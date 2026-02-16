/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mem;
    
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        if (mem.contains(node)) {
            return mem[node];
        }

        Node* newNode = new Node(node->val);
        mem[node] = newNode;

        for (auto nei: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(nei));
        }

        return newNode;
    }
};