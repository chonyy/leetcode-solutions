class Solution {
public:
    bool createGraph(unordered_map<char,vector<int>>& graph, unordered_map<char,int>& inDegree, vector<string>& words) {
        int n = words.size();
        for(int i = 1; i < n; i ++) {
            string& w1 = words[i-1];
            string& w2 = words[i];
            
            int p1 = 0;
            int p2 = 0;
            
            while(p1 < w1.size() && p2 < w2.size()) {
                if(w1[p1] != w2[p2]) {
                    break;
                }
                p1 ++;
                p2 ++;
            }
            
            if(p1 < w1.size() && p2 < w2.size()) {
                graph[w1[p1]].push_back(w2[p2]);
                inDegree[w2[p2]] ++;
            }
            else if(w1.size() > w2.size()) {
                return false;
            }
            
        }
        
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<int>> graph;
        unordered_map<char,int> inDegree;
        
        for(int i  = 0; i < words.size(); i ++) {
            for(char c : words[i]) {
                inDegree[c] = 0;
            }
        }
        
        if(createGraph(graph, inDegree, words) == false)
            return "";
        
        queue<char> q;
        
        for(auto entry : inDegree) {
            // cout << entry.first << " " << entry.second << endl;
            if(entry.second == 0)
                q.push(entry.first);
        }
        
        
        string res = "";
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            res += cur;
            auto& neighbors = graph[cur];
            for(auto nei : neighbors) {
                inDegree[nei] --;
                if(inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        return res.size() == inDegree.size() ? res : "";
    }
};