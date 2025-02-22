/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        stack<TreeNode*> stk;

        stk.push(new TreeNode(getNumber(traversal, idx)));

        while(idx < traversal.size()) {
            int dash = 0;

            while(traversal[idx] == '-') {
                idx ++;
                dash ++;
            }

            while(stk.size() > dash) {
                stk.pop();
            }

            int val = getNumber(traversal, idx);
            TreeNode* node = new TreeNode(val);
            // cout << "val: " << val << endl;

            if(stk.top()->left == nullptr) {
                // cout << "set left" << endl;
                stk.top()->left = node;
            }
            else {
                // cout << "set right" << endl;
                stk.top()->right  = node;
            }

            // cout << "idx: " << idx << endl;
            stk.push(node);
        }

        while(stk.size() > 1) {
            stk.pop();
        }

        return stk.top();
    }
    
    int getNumber(string& traversal, int& idx) {
        int num = 0;

        while(isdigit(traversal[idx])) {
            num = num * 10 + traversal[idx] - '0';
            idx ++;
        }

        return num;
    }
};