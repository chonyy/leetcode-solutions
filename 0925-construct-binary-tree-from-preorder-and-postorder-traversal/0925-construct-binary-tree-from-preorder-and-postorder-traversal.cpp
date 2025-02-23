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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        int n = postorder.size();

        for(int i = 0; i < n; i ++) {
            m[postorder[i]] = i;
        }

        int idx = 0;

        return build(idx, preorder, m, preorder.size());
    }
    
    TreeNode* build(int& idx, vector<int>& preorder, unordered_map<int,int>& m, int prevPostIdx) {
        if(idx >= preorder.size()) {
            return nullptr;
        }

        int val = preorder[idx];
        int postIdx = m[val];
        
        if(postIdx > prevPostIdx) {
            return nullptr;
        }

        idx ++;
        TreeNode* node = new TreeNode(val);

        node->left = build(idx, preorder, m, postIdx);
        node->right = build(idx, preorder, m, postIdx);

        return node;
    }
};