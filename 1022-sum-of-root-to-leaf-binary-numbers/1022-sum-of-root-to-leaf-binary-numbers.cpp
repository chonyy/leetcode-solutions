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
    void solve(TreeNode* root, int& res, int cur) {
        if(!root) {
            return;
        }
        
        cur <<= 1;
        cur = cur | root->val;
        
        if(!root->left && !root->right) {
            res += cur;
            return;
        }
        
        solve(root->left, res, cur);
        solve(root->right, res, cur);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        int cur = 0;
        solve(root, res, cur);
        
        return res;
    }
};