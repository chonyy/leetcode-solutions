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
    unordered_map<int,int> inOrderValToIdx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i ++) {
            inOrderValToIdx[inorder[i]] = i;
        }

        int idx = 0;
        return build(idx, preorder, 0, n-1, inorder);
    }

    TreeNode* build(int& preIdx, vector<int>& preorder, int left, int right, vector<int>& inorder) {
        // base cases
        // cout << preIdx << " " << left << " " << right << endl;
        if (preIdx >= preorder.size() || left >= preorder.size() || right < 0) {
            return nullptr;
        }
        
        if (left > right) {
            return nullptr;
        }

        // build node
        // increment index
        int val = preorder[preIdx];
        TreeNode* node = new TreeNode(val);
        int inIdx = inOrderValToIdx[val];
        preIdx ++;

        // build left
        node->left = build(preIdx, preorder, left, inIdx-1, inorder);

        // build right
        node->right = build(preIdx, preorder, inIdx+1, right, inorder);

        return node;
    }
};

// 3,9,20,15,7
// x

// preIdx:0

// 9,3,15,20,7
//   x

// inIdx: 1


