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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        find(root, startValue, startPath);
        string destPath = "";
        find(root, destValue, destPath);

        int prefixLen = 0;
        while (!startPath.empty() && !destPath.empty()) {
            if (startPath.back() == destPath.back()) {
                startPath.pop_back();
                destPath.pop_back();
            }
            else {
                break;
            }
        }

        int remainStartLen = startPath.size();
        string startUpward = "";
        for (int i = 0; i < remainStartLen; i ++) {
            startUpward += "U";
        }

        reverse(destPath.begin(), destPath.end());
        return startUpward + destPath;
    }

    bool find(TreeNode* root, int val, string& path) {
        if (!root) {
            return false;
        }

        if (root->val == val) {
            return true;
        }

        bool left = find(root->left, val, path);
        bool right = find(root->right, val, path);

        if (left) {
            // cout << "find left" << endl;
            path += 'L';
            return true;
        }
        else if (right) {
            // cout << "find right" << endl;
            path += 'R';
            return true;
        }

        return false;
    }
};