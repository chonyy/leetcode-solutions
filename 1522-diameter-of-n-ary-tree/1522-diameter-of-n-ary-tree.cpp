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
    int ans = 0;
    
    int solve(Node* root) {
        if(!root)
            return 0;
        
        int sum = 0;
        int maxx = 0;
        int secondMax = 0;
        // cout << "root " << root->val << endl;
        
        for(auto child : root->children) {
            int val = solve(child);
            if(val > maxx) {
                secondMax = maxx;
                maxx = val;
            }
            else if(val > secondMax) {
                secondMax = val;
            }
        }
        // cout << maxx << " " << secondMax << endl;
        ans = max(ans, maxx + secondMax);
        
        return max(maxx, secondMax) + 1;
    }
    
    int diameter(Node* root) {
        solve(root);
        return ans;
    }
};