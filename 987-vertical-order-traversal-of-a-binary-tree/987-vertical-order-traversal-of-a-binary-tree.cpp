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
    int minVertical = 0;
    int maxVertical = 0;
    // <min, max>
    unordered_map<int, pair<int,int>> colBoundary;
    
    void dfs(TreeNode* root, unordered_map<int, unordered_map<int,multiset<int>>>& table, int vertical, int horizontal) {
        if(!root) {
            return;
        }
        
        // put in table
        // update vertical min/max
        // update horizontal min/max
        table[vertical][horizontal].insert(root->val);
        
        minVertical = min(minVertical, vertical);
        maxVertical = max(maxVertical, vertical);
        
        if(colBoundary.find(vertical) == colBoundary.end()) {
            colBoundary[vertical] = {horizontal, horizontal};
        }
        colBoundary[vertical].first = min(colBoundary[vertical].first, horizontal);
        colBoundary[vertical].second = max(colBoundary[vertical].second, horizontal);
        
        // go to next level
        dfs(root->left, table, vertical-1, horizontal+1);
        dfs(root->right, table, vertical+1, horizontal+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, unordered_map<int,multiset<int>>> table;
        
        dfs(root, table, 0, 0);
        
        vector<vector<int>> res;
        
        // loop through row and col
        for(int i = minVertical; i <= maxVertical; i ++) {
            int minRow = colBoundary[i].first;
            int maxRow = colBoundary[i].second;
            vector<int> colTemp;
            
            for(int j = minRow; j <= maxRow; j ++) {
                auto& values = table[i][j];
                for(auto val : values) {
                    colTemp.push_back(val);
                }
            }
            res.push_back(colTemp);
        }
        
        return res;
    }
};