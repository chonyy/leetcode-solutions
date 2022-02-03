class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> inDegrees;
        
        for(int i = 0; i < n; i ++) {
            if(leftChild[i] != -1) {
                inDegrees[leftChild[i]] ++;
            }
            if(rightChild[i] != -1) {
                inDegrees[rightChild[i]] ++;
            }
        }
        
        int root = -1;
        for(int i = 0; i< n; i ++) {
            if(inDegrees[i] == 0) {
                if(root != -1)
                    return false;
                root = i;
            }
        }
        
        // no root
        if(root == -1)
            return false;
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(root);
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if(visited.find(cur) != visited.end()) {
                return false;
            }
            visited.insert(cur);
            
            if(leftChild[cur] != -1) {
                q.push(leftChild[cur]);
            }
            if(rightChild[cur] != -1) {
                q.push(rightChild[cur]);
            }
        }
        
        return visited.size() == n;
    }
};