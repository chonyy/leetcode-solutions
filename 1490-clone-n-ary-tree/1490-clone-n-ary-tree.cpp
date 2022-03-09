/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root)
            return nullptr;
        
        auto& children = root->children;
        Node* newRoot = new Node(root->val);
        
        for(auto& child : children) {
            newRoot->children.push_back(cloneTree(child));
        }
        
        return newRoot;
    }
};