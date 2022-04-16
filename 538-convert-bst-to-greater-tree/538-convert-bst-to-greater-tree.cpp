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
    int solve(TreeNode* root, int larger) {
        if(!root) {
            return larger;
        }
        
        int right = solve(root->right, larger);
        int newLarger = right + root->val;
        root->val = newLarger;
        int left = solve(root->left, newLarger);
        
        return left;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        solve(root, 0);
        return root;
    }
};