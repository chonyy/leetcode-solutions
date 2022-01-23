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
    int solve(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        res = max(res, left+right);
        
        return 1 + max(left, right);
    }
    
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res;
    }
};