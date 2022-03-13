class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        unordered_map<int, unordered_map<char,int>> colorCnt;

        // create graph
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            inDegree[e[1]] ++;
        }

        queue<int> q;
        // get starting points
        for(int i = 0; i < n; i ++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int res = 0;
        int count = 0;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            count ++;
            auto& colorMap = colorCnt[cur];
            colorMap[colors[cur]] ++;
            for(auto& entry : colorMap) {
                res = max(entry.second, res);
            }
            
            auto& neighbors = graph[cur];
            for(auto& nei : neighbors) {
                // update max
                for(char i = 'a'; i <= 'z'; i ++) {
                    colorCnt[nei][i] = max(colorCnt[nei][i], colorMap[i]);
                }
                
                // update indegree
                if(--inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        return count == n ? res : -1;
    }
};