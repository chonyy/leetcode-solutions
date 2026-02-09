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

    void findGood(TreeNode* root, int curMax) {
        if (!root) {
            return;
        }

        if (root->val >= curMax) {
            res ++;
        }

        findGood(root->left, max(curMax, root->val));
        findGood(root->right, max(curMax, root->val));
    }

    int goodNodes(TreeNode* root) {
        findGood(root, INT_MIN);
        
        return res;
    }
};