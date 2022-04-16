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
    int solve(TreeNode* root, int large) {
        if(!root) {
            return large;
        }
        
        int right = solve(root->right, large);
        int left = solve(root->left, right + root->val);
        
        root->val = root->val + right;
        
        return left;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        solve(root, 0);
        return root;
    }
};