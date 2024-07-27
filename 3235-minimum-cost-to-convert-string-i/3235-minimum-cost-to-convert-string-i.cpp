class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> graph;
    unordered_map<char, unordered_map<char, int>> shortest;

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        for(int i = 0; i < n; i ++) {
            graph[original[i]].push_back({cost[i], changed[i]});
        }

        for(char c : source) {
            shortestPath(c);
        }

        int m = source.size();
        long long res = 0;
        for(int i = 0; i < m; i ++) {
            if(shortest[source[i]].count(target[i]) == 0) {
                return -1;
            }
            res += shortest[source[i]][target[i]];
        }

        return res;
    }

    int shortestPath(char start) {
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
        pq.push({0, start});

        while(!pq.empty()) {
            char curNode = pq.top().second;
            int curDist = pq.top().first;
            pq.pop();

            if(shortest[start].count(curNode)) {
                continue;
            }

            shortest[start][curNode] = curDist;

            auto& neighbors = graph[curNode];
            for(auto& nei : neighbors) {
                char newNode = nei.second;
                int dist = nei.first;

                pq.push({curDist + dist, newNode});
            }
        }

        return -1;
    }
};