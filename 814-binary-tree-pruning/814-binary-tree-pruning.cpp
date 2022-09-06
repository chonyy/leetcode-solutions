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
    TreeNode* pruneTree(TreeNode* root) {
        return containOne(root) ? root : nullptr;
    }
    
    bool containOne(TreeNode* root) {
        if(!root) {
            return false;
        }
        
        bool leftContain = containOne(root->left);
        bool rightContain = containOne(root->right);
        
        if(!leftContain)
            root->left = nullptr;
        if(!rightContain) {
            root->right = nullptr;
        }
        
        return leftContain || rightContain || root->val == 1;
    }
};