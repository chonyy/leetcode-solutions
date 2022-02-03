/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int count = 0;
    
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        
        auto left = solve(root->left, p, q);
        auto right = solve(root->right, p, q);
        
        if(root == p || root == q) {
            count ++;
            return root;
        }
        
        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto node = solve(root, p, q);
        
        return count == 2 ? node : nullptr;
    }
};