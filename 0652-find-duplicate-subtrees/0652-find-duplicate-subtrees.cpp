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
    int curId = 1;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> serialToId;
        unordered_map<int, int> count;
        solve(res, count, serialToId, root);
        return res;
    }

    int solve(vector<TreeNode*>& res, unordered_map<int, int>& count, unordered_map<string, int>& serialToId, TreeNode* cur) {
        if(!cur)
            return 0;

        int leftId = solve(res, count, serialToId, cur->left);
        int rightId = solve(res, count, serialToId, cur->right);
        string serial = to_string(cur->val) + "," + to_string(leftId) + "," + to_string(rightId);
        if(serialToId.count(serial) == 0) {
            serialToId[serial] = curId;
            curId ++;
        }
        int serialId = serialToId[serial];
        count[serialId] ++;
        if(count[serialId] == 2)
            res.push_back(cur);

        return serialId;
    }
};