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
    Node* clone(Node* node, unordered_map<Node*, Node*>& seen) {
        if(seen.find(node) != seen.end()) {
            return seen[node];
        }
        
        if(!node)
            return nullptr;
        
        Node* newNode = new Node(node->val);
        seen[node] = newNode;
        
        auto& neighbors = node->neighbors;
        for(auto nei : neighbors) {
            newNode->neighbors.push_back(clone(nei, seen));
        }
        
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> seen;
        
        return clone(node, seen);
    }
};