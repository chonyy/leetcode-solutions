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
    void solve(TreeNode* root, int val, int& ans) {
        if(!root) {
            return;
        }
        
        int newVal = val * 10 + root->val;
        // cout << newVal << endl;
        if(!root->left && !root->right) {
            ans += newVal;
            return;
        }
        if(root->left)
            solve(root->left, newVal, ans);
        if(root->right)
            solve(root->right, newVal, ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};