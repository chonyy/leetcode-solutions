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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        findMax(root);
        return res;
    }

    int findMax(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = findMax(root->left);
        int right = findMax(root->right);

        int takeOne = max(left, right) + root->val;
        int takeNone = root->val;
        int takeBoth = left + right + root->val;

        int choice = max(takeOne, takeNone);
        choice = max(choice, takeBoth);
        res = max(res, choice);

        return max(takeNone, takeOne);
    }
};