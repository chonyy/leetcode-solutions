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
    TreeNode* res;
    
    void solve(TreeNode* root) {
        if(!root) {
            return;
        }
        
        solve(root->left);
        // cout << root->val << endl;
        root->left = nullptr;
        res->right = root;
        res = res->right;
        
        if(!root->right) {
            return;
        }
        
        solve(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* sentinel = new TreeNode();
        res = sentinel;
        solve(root);
        return sentinel->right;
    }
};