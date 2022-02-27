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
    // 0: not covered
    // 1: camera here
    // 2: covered, no camera
    int dfs(TreeNode* root) {
        if(!root)
            return 2;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        // cout <<"left " << left << endl;
        // cout << "right " << right << endl;
        
        // all children covered but no camera
        if(left == 2 && right == 2)
            return 0;
        
        // children need cover
        if(left == 0 || right == 0) {
            // add cam
            res ++;
            return 1;
        }
        
        return 2;
    }
    
    int res = 0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root) == 0) + res;
    }
};