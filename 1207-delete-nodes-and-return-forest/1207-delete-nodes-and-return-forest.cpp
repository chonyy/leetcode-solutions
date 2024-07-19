class Solution {
public:
    TreeNode* solve(TreeNode* root, unordered_set<int>& del, vector<TreeNode*>& res, bool isRoot) {
        if(!root)
            return nullptr;
        
        bool deleted = del.find(root->val) != del.end();
        
        if(isRoot && !deleted) {
            res.push_back(root);
        }
        
        root->left = solve(root->left, del, res, deleted);
        root->right = solve(root->right, del, res, deleted);
        
        return deleted ? nullptr : root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        
        solve(root, del, res, true);
        return res;
    }
};