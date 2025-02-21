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
class FindElements {
public:
    unordered_set<int> seen;
    queue<pair<TreeNode*, int>> q;

    FindElements(TreeNode* root) {
        traverse(root);        
    }

    void traverse(TreeNode* root) {
        q.push({root, 0});

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            if(!cur.first) {
                continue;
            }

            int val = cur.second;
            seen.insert(val);

            q.push({cur.first->left, 2 * val + 1});
            q.push({cur.first->right, 2 * val + 2});
        }
    }
    
    bool find(int target) {
        return seen.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */