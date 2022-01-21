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

// 2 (3) (1)
    
// 2

//     2
//   /   \
// 3       1
    
class Solution {
public:
    TreeNode* str2tree(string s) {
        stack<TreeNode*> stk;
        int i = 0;
        int n = s.size();
        int sign = 1;
        
        if(s.size() == 0) {
            return nullptr;
        }
        
        while(i < n) {
            if(isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                TreeNode* newNode = new TreeNode(sign * num);
                sign = 1;
                stk.push(newNode);
            }
            if(s[i] == '-') {
                sign = -1;
                i ++;
            }
            if(s[i] == '(') {
                i ++;
            }
            if(s[i] == ')') {
                auto cur = stk.top();
                stk.pop();
                auto& parent = stk.top(); 
                
                if(parent->left) {
                    parent->right = cur;
                }
                else {
                    parent->left = cur;
                }
                
                i ++;
            }
        }
    
        
        return stk.top();
    }
};