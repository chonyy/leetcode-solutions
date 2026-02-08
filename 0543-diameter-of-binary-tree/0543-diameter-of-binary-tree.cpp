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
    int res = 0;

    // return max branch depth
    int solve(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftDepth = solve(root->left);
        int rightDepth = solve(root->right);

        res = max(res, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res;
    }
};