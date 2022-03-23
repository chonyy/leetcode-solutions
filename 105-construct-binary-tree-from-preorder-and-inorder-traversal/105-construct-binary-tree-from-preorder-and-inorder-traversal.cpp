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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if(preEnd < preStart || inEnd < inStart)
            return nullptr;
        
        if(preEnd == preStart || inEnd == inStart)
            return new TreeNode(preorder[preStart]);
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find the index in inorder
        int inIdx = -1;
        for(int i = inStart; i <= inEnd; i ++) {
            if(inorder[i] == rootVal) {
                inIdx = i;
                break;
            }
        }
        
        int leftNodeNum = inIdx - inStart;
        
        // Construct the left and right tree
        root->left = helper(preorder, inorder, preStart+1, preStart+leftNodeNum, inStart, inIdx-1);
        root->right = helper(preorder, inorder, preStart+leftNodeNum+1, preEnd, inIdx+1, inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
};