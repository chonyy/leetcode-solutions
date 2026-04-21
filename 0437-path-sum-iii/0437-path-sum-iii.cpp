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
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        findPath(root, targetSum, res);
        return res;
    }

    vector<pair<int,long long>> findPath(TreeNode* root, int targetSum, int& res) {
        if (!root) {
            return {};
        }

        // create finalPaths
        vector<pair<int,long long>> finalPaths;

        // add leftPath to finalPaths
        // add rightPath to finalPaths
        // add 0,0 to finalPath
        auto leftPath = findPath(root->left, targetSum, res);
        finalPaths.insert(finalPaths.begin(), leftPath.begin(), leftPath.end());
        auto rightPath = findPath(root->right, targetSum, res);
        finalPaths.insert(finalPaths.begin(), rightPath.begin(), rightPath.end());
        finalPaths.push_back({0, 0});;

        // loop finalPaths
        // - path += 1
        // - sum += node->val
        // - check for res and increment
        for (auto& pathSum : finalPaths) {
            pathSum.first += 1;
            pathSum.second += root->val;
            // cout << pathSum.first << " " << pathSum.second << endl;

            if (pathSum.second == targetSum) {
                res ++;
            }
        }

        return finalPaths;
    }
};