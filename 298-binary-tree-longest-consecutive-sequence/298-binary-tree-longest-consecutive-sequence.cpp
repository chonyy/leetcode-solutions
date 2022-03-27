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
    int ans;
    
    void solve(TreeNode* root, int prev, int combo) {
        if(!root) {
            return;
        }
        
        if(root->val == prev+1) {
            combo ++;
            ans = max(ans, combo);
        }
        else {
            combo = 1;
        }
        
        solve(root->left, root->val, combo);
        solve(root->right, root->val, combo);
    }
    
    int longestConsecutive(TreeNode* root) {
        ans = 1;
        solve(root, INT_MIN, 1);
        return ans;
    }
};