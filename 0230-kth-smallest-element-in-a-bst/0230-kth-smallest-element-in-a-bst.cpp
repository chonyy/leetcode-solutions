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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                // cout << root->val << endl;
                root = root->left;
            }

            // get number
            TreeNode* cur = stk.top();
            stk.pop();

            k --;
            if (k == 0) {
                return cur->val;
            }
            
            // continue right
            root = cur->right;
        }

        return -1;
    }
};