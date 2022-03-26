class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int,int> inDegree;
        int n = nums.size();
        
        for(auto& seq : sequences) {
            int m = seq.size();
            if(seq[0] < 1 || seq[0] > n) {
                // cout << "first bound" << endl;
                return false;
            }
            for(int i = 1; i < m; i ++) {
                if(seq[i] < 1 || seq[i] > n) {
                    // cout << "mid bound" << endl;
                    return false;   
                }
                
                if(graph[seq[i-1]].count(seq[i]) == 0) {
                    inDegree[seq[i]] ++;
                    graph[seq[i-1]].insert(seq[i]);
                }
            }
        }
        
        // topo sort
        queue<int> q;
        vector<int> res;
        for(int i = 1; i <= n; i ++) {
            if(inDegree[i] == 0) {
                // cout << i << endl;
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            if(q.size() > 1) {
                // cout << "fail" << endl;
                return false;
            }
            
            auto cur = q.front();
            q.pop();
            res.push_back(cur);
            
            auto& neighbors = graph[cur];
            for(auto& nei : neighbors) {
                inDegree[nei] --;
                if(inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        // for(int num : res) {
        //     cout << num << " ";
        // }
        // cout << endl;
        
        return res == nums;
    }
};