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
    void flatten(TreeNode* root) {
        flatt(root, nullptr);
    }
    
    TreeNode* flatt(TreeNode* root, TreeNode* prev) {
        if(!root) {
            return prev;
        }
        
        prev = flatt(root->right, prev);
        prev = flatt(root->left, prev);
        root->right = prev;
        root->left = nullptr;
        
        return root;
    }
};