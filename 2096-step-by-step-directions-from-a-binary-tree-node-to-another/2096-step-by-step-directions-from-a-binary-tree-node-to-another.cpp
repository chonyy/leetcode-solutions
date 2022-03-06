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
    bool getPath(TreeNode* root, int val, string& path) {
        if(!root)
            return false;
        if(root->val == val)
            return true;
        
        bool left = getPath(root->left, val, path);
        bool right = getPath(root->right, val, path);
        
        if(left) {
            path += 'L';
            return true;
        }
        else if(right) {
            path += 'R';
            return true;
        }
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string destPath = "";
        
        getPath(root, startValue, startPath);
        getPath(root, destValue, destPath);
        
        while(!startPath.empty() && !destPath.empty()) {
            if(startPath.back() != destPath.back())
                break;
            startPath.pop_back();
            destPath.pop_back();
        }
        
        string newStart = "";
        newStart.append(startPath.size(), 'U');
        reverse(destPath.begin(), destPath.end());
        
        return newStart + destPath;
    }
};