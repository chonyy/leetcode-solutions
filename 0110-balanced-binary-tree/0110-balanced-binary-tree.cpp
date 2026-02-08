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
    pair<bool,int> balance(TreeNode* node) {
        if (! node) {
            return {true, 1};
        }

        auto left = balance(node->left);
        auto right = balance(node->right);

        // already in ballance
        if (left.first == false || right.first == false) {
            return {false, -1};
        }

        // check height
        int diff = abs(left.second - right.second);
        if (diff > 1) {
            return {false, -1};
        }

        return {true, max(left.second, right.second) + 1};
    }

    bool isBalanced(TreeNode* root) {
        return balance(root).first;
    }
};