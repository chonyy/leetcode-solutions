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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int ans = 0;
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            ans = cur->val;
            
            if(cur->right) {
                q.push(cur->right);
            }
            if(cur->left) {
                q.push(cur->left);
            }
        }
        
        return ans;
    }
};