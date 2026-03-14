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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        // found the node

        // return nullptr if no children
        if (!root->left && !root->right) {
            return nullptr;
        }

        // if right is empty, replace with left
        // if left is empty, replace with right
        if (!root->right) {
            return root->left;
        }

        if (!root->left) {
            return root->right;
        }

        // find the smallest on the left
        // replace delete the smalltest fromt right
        // return smallest
        TreeNode* smallest = root->right;
        while(smallest->left != nullptr) {
            smallest = smallest->left;
        }

        TreeNode* newRight = deleteNode(root->right, smallest->val);
        smallest->right = newRight;

        smallest->left = root->left;
        
        delete root;

        return smallest;
    }
};