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
    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right) {
            return true;
        }

        return solve(root, nullptr, nullptr);
    }

    bool solve(TreeNode* root, TreeNode* upper, TreeNode* lower) {
        if (!root) {
            return true;
        }

        int val = root->val;
        if (lower && val <= lower->val) {
            return false;
        }

        if (upper && val >= upper->val) {
            return false;
        }

        return solve(root->left, root, lower) && solve(root->right, upper, root);
    }
};