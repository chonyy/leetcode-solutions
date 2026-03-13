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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        insert(root, val);
        return root;
    }

    void insert(TreeNode* root, int val) {
        if (!root) {
            return;
        }

        if (root->val < val) {
            if (root->right) {
                insert(root->right, val);
                return;
            }
            else {
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return;
            }
        }

        // smaller
        if (root->left) {
            insert(root->left, val);
            return;
        }

        TreeNode* node = new TreeNode(val);
        root->left = node;
        return;
    }
};