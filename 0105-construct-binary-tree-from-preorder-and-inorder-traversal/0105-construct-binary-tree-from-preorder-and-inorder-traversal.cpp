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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;

        for(int i = 0; i < inorder.size(); i ++) {
            m[inorder[i]] = i;
        }

        int idx = 0;

        return build(idx, preorder, m, 0, inorder.size() - 1);
    }

    TreeNode* build(int& idx, vector<int>& preorder, unordered_map<int,int>& m, int leftBound, int rightBound) {
        if(idx >= preorder.size()) {
            return nullptr;
        }

        int val = preorder[idx];
        int inIdx = m[val];

        if(inIdx < leftBound || inIdx > rightBound) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(val);
        idx ++;

        node->left = build(idx, preorder, m, leftBound, inIdx - 1);
        node->right = build(idx, preorder, m, inIdx + 1, rightBound);

        return node;
    }
};