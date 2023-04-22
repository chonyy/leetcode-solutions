class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) 
            return 0;
        
        unsigned long long ans = 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            unsigned long long l = q.front().second;
            unsigned long long r = l; // right started same as left
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                
                if (node->left) 
                    q.push({node->left, (unsigned long long)r * 2});
                if (node->right) 
                    q.push({node->right, (unsigned long long)r * 2 + 1});
            }
            
            ans = max(ans, r + 1 - l);
        }
        
        return ans;
    }
};