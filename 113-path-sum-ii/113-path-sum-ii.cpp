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
    void traverse(TreeNode* root, int target, vector<int>& temp, vector<vector<int>>& res, int curSum) {
        if(!root)
            return;
        
        curSum += root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(curSum == target)
                res.push_back(temp);
            temp.pop_back();
            return;
        }
        
        traverse(root->left, target, temp, res, curSum);
        traverse(root->right, target, temp, res, curSum);
        temp.pop_back();
    }    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        
        traverse(root, targetSum, temp, res, 0);
        
        return res;
    }
};