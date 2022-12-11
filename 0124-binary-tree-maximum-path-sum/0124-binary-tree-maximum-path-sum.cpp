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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
    
    int solve(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        left = max(left, 0);
        right = max(right, 0);
        
        ans = max(ans, root->val + left + right);
        return root->val + (right > left ? right : left);
    }
};