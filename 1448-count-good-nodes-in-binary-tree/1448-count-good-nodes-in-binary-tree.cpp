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
int good = 0;
    int goodNodes(TreeNode* root) {
        count(root, root->val);
        return good;
    }

    void count(TreeNode* root, int curMax) {
        if(!root)
            return;

        if(root->val >= curMax)
            good ++;

        count(root->left, max(curMax, root->val));
        count(root->right, max(curMax, root->val));
    }
};