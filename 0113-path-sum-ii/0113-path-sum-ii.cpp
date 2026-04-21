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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;

        findPath(root, targetSum, temp, res);

        return res;
    }

    void findPath(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& res) {
        if (!root) {
            return;
        }

        temp.push_back(root->val);
        findPath(root->left, targetSum - root->val, temp, res);
        findPath(root->right, targetSum - root->val, temp, res);

        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(temp);
        }

        temp.pop_back();
        return;
    }
};