class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> inDegree;

        for (int i = 0; i < n; i ++) {
            inDegree[leftChild[i]] ++;
            inDegree[rightChild[i]] ++;
        }

        
        int root = -1;
        
        for (int i = 0; i < n; i ++) {
            if (inDegree[i] == 0) {
                if (root != -1) { // more than one root
                    return false;
                }

                root = i;
            }
        }

        if (root == -1) { // no root
            return false;
        }

        queue<int> q;
        q.push(root);
        unordered_set<int> visited;

        while (!q.empty()) {
            int node = q.front();
            // cout << node << endl;
            q.pop();

            if (visited.contains(node)) {
                return false;
            }

            visited.insert(node);

            int left = leftChild[node];
            if (left != -1) {
                q.push(left);
            }

            int right = rightChild[node];
            if (right != -1) {
                q.push(right);
            }
        }

        return visited.size() == n;
    }
};