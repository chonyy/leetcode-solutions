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
    TreeNode* startNode;

    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        dfs(nullptr, root, k, graph);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(startNode);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (visited.contains(cur)) {
                continue;
            }
            visited.insert(cur);

            // return when leaf
            if (!cur->left && !cur->right) {
                return cur->val;
            }

            // explore nei
            // push nei to q
            auto& neighbors = graph[cur];
            for (auto nei : neighbors) {
                q.push(nei);
            }
        }

        return -1;
    }

    // build graph
    // point startNode when node->val == k
    void dfs(TreeNode* prev, TreeNode* root, int k, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (root == nullptr) {
            return;
        }

        if (prev) {
            graph[prev].push_back(root);
            graph[root].push_back(prev);
        }

        if (root->val == k) {
            startNode = root;
        }

        dfs(root, root->left, k, graph);
        dfs(root, root->right, k, graph);
    }
};