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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 0)
            return {};
        
        if(n == 1) {
            return {new TreeNode(0)};
        }
        
        if(n % 2 == 0)
            return {};
        
        vector<TreeNode*> res;
        
        for(int i = 0; i < n; i ++) {
            int r = n - 1- i;
            
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(r);
            
            for(auto& lNode : left) {
                for(auto& rNode : right) {
                    res.push_back(new TreeNode(0, lNode, rNode));
                }
            }
        }
        
        return res;
    }
};