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

    FindElements(TreeNode* root) {
        traverse(root, 0);        
    }

    void traverse(TreeNode* root, int val) {
        if(!root) {
            return;
        }

        seen.insert(val);

        traverse(root->left, 2 * val + 1);
        traverse(root->right, 2 * val + 2);
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