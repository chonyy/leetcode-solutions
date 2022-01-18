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
    
    void traverse(TreeNode* root, unordered_map<int,int>& seen, int target, int curSum) {
        if(!root)
            return;
        
        curSum += root->val;
        
        // check val
        if(seen.find(curSum - target) != seen.end())
            res += seen[curSum - target];
        
        seen[curSum] += 1;
        traverse(root->left, seen, target, curSum);
        traverse(root->right, seen ,target, curSum);
        
        seen[curSum] -= 1;
        if(seen[curSum] == 0)
            seen.erase(curSum);
    }    
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> seen;
        seen[0] = 1;
        traverse(root, seen, targetSum, 0);
        
        return res;
    }
};