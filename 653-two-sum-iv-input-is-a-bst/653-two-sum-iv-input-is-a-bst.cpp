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
    bool check(TreeNode* root, unordered_set<int>& set, int target) {
        if(!root) {
            return false;
        }
        
        if(set.count(root->val)) {
            return true;
        }
        
        set.insert(target-root->val);
        
        return check(root->left, set, target) || check(root->right, set, target);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        
        return check(root, set, k);
    }
};