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
    int ans;
    
    vector<int> dfs(TreeNode* root, int dist) {
        vector<int> map(dist+1, 0);
        if(!root) {
            return map;
        }
        if(!root->left && !root->right) {
            map[1] = 1;
            return map;
        }
        
        // cout << root->val << endl;
        auto l = dfs(root->left, dist);
        auto r = dfs(root->right, dist);
        
        for(int i = 0; i <= dist; i ++) {
            for(int j = 0; j <= dist; j ++) {
                if(i + j <= dist) {
                    ans += l[i] * r[j];
                }
            }
        }
        
        // create new map
        for(int i = dist; i > 0 ; i --) {
            map[i] = l[i-1] + r[i-1];
            // cout << i << " " << map[i] << endl;
        }
        // cout << endl;
        return map;
    }
    
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        dfs(root, distance);
        return ans;
    }
};