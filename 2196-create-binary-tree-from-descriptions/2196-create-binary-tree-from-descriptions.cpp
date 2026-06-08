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
    unordered_map<int, TreeNode*> mapping;
    unordered_map<TreeNode*, int> parentCount;

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for (auto& d : descriptions) {
            createNodes(d[0], d[1], d[2]);
        }

        TreeNode* root;
        for (auto& entry : parentCount) {
            auto node = entry.first;
            auto parent = entry.second;

            if (parent == 0) {
                root = node;
            }
        }

        return root;
    }

    void createNodes(int parent, int child, bool left) {
        if (!mapping.contains(parent)) {
            mapping[parent] = new TreeNode(parent);
            parentCount[mapping[parent]] = 0;
        }

        if (!mapping.contains(child)) {
            mapping[child] = new TreeNode(child);
            parentCount[mapping[child]] = 0;
        }

        if (left) {
            mapping[parent]->left = mapping[child];
        }
        else {
            mapping[parent]->right = mapping[child];
        }

        parentCount[mapping[child]] ++;
    }
};