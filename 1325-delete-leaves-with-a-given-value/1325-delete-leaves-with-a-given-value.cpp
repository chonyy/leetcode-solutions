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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }

        TreeNode* newLeft = removeLeafNodes(root->left, target);
        TreeNode* newRight = removeLeafNodes(root->right, target);

        if (newLeft == nullptr && newRight == nullptr && root->val == target) {
            return nullptr;
        }
        
        root->left = newLeft;
        root->right = newRight;

        return root;
    }
};