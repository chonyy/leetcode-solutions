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
    unordered_map<int,int> inorderValToIdx;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        for (int i = 0; i < inorder.size(); i ++) {
            inorderValToIdx[inorder[i]] = i;
        }

        return build(preorder, preIdx, inorder, 0, preorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int& preIdx, vector<int>& inorder, int inStart, int inEnd) {
        if (preIdx >= preorder.size()) {
            return nullptr;
        }

        if (inStart > inEnd) {
            return nullptr;
        }

        int val = preorder[preIdx];
        preIdx ++;

        int inIdx = inorderValToIdx[val];

        TreeNode* node = new TreeNode(val);
        
        node->left = build(preorder, preIdx, inorder, inStart, inIdx - 1);
        node->right = build(preorder, preIdx, inorder, inIdx + 1, inEnd);

        return node;
    }
};