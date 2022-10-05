class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        else if (d == 0) {
            TreeNode* newroot = new TreeNode(v);
            newroot->right = root;
            return newroot;
        }

        if (!root) {
            return nullptr;
        }
        else if (d == 2) {
            root->left  = addOneRow(root->left,  v, 1);
            root->right = addOneRow(root->right, v, 0);
            return root;
        }
        else if (d > 2) {
            root->left  = addOneRow(root->left,  v, d - 1);
            root->right = addOneRow(root->right, v, d - 1);
        }
        return root;
    }
};