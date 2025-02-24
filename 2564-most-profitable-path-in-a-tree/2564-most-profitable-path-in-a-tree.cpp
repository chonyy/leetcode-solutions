class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int, int> nodeToTime;
        unordered_map<int, vector<int>> graph;

        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited;
        nodeToTime[bob] = 0;
        getTime(graph, nodeToTime, visited, bob, 0);

        // for(auto& entry : nodeToTime) {
        //     cout << entry.first << " " << entry.second << endl;
        // }

        int res = INT_MIN;

        visited.clear();
        getProfit(graph, nodeToTime, visited, amount, res);

        return res;
    }

    void getProfit(unordered_map<int, vector<int>>& graph, unordered_map<int,int>& nodeToTime, unordered_set<int>& visited, vector<int>& amount, int& res) {
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {0, 0}}); // node, amount, time

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            int node = cur.first;
            int curAmount = cur.second.first;
            int time = cur.second.second;

            // Add amount
            int bobTime = nodeToTime.count(node) ? nodeToTime[node] : INT_MAX;
            // cout << "Node: " << node << endl;
            if(bobTime == time) {
                // cout << "same time add " << amount[node] / 2 << endl;;
                curAmount += amount[node] / 2;
            }
            else if(bobTime > time) {
                // cout << "Alice fast add " << amount[node] << endl;;
                curAmount += amount[node];
            }
            else {
                // cout << "Alice slow" << endl;
                // get nothing
            }

            // get max result if leaf
            if(graph[node].size() == 1 && time != 0) {
                // cout << "reach leaf" << endl;
                res = max(res, curAmount);
            }
            visited.insert(node);

            auto& neighbors = graph[node];
            for(auto nei : neighbors) {
                if(visited.count(nei)) {
                    continue;
                }

                q.push({nei, {curAmount, time + 1}});
            }
        }
    }

    bool getTime(unordered_map<int, vector<int>>& graph, unordered_map<int,int>& nodeToTime, unordered_set<int>& visited, int node, int time) {
        if(node == 0) {
            nodeToTime[node] = time;
            return true;
        }

        auto& neighbors = graph[node];
        visited.insert(node);

        for(auto& nei : neighbors) {
            if(visited.count(nei)) {
                continue;
            }

            // cout << "time " << time << "visit " << nei << endl;

            if(getTime(graph, nodeToTime, visited, nei, time + 1)) {
                // cout << "node " << node << " time " << time << endl;
                nodeToTime[node] = time;
                return true;
            }
        }

        visited.erase(node);
        return false;
    }
};