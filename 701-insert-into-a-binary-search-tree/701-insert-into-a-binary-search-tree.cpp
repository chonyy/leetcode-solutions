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
    void insert(TreeNode* root, int val) {
        if(!root) {
            return;
        }
        
        if(val > root->val) {
            if(!root->right) {
                root->right = new TreeNode(val);
                return;
            }
            insert(root->right, val);
        }
        if(val < root->val) {
            if(!root->left) {
                root->left = new TreeNode(val);
                return;
            }
            insert(root->left, val);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root, val);
        return root == nullptr ? new TreeNode(val) : root;
    }
};