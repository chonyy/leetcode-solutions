/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void createGraph(TreeNode* parent, TreeNode* child, unordered_map<TreeNode*,vector<TreeNode*>>& graph) {
        if(parent) {
            graph[parent].push_back(child);
            graph[child].push_back(parent);
        }
        
        if(child->left) {
            createGraph(child, child->left, graph);
        }
        if(child->right) {
            createGraph(child, child->right, graph);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        createGraph(nullptr, root, graph);
        vector<int> res;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        
        for(int i = 0; i < k; i ++) {
            int size = q.size();
            for(int j = 0; j < size; j ++) {
                auto cur = q.front();
                visited.insert(cur);
                q.pop();
                auto& neighbors = graph[cur];
                for(auto nei : neighbors) {
                    if(visited.find(nei) != visited.end())
                        continue;
                    q.push(nei);   
                }
            }
        }
        
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        
        return res;
    }
};