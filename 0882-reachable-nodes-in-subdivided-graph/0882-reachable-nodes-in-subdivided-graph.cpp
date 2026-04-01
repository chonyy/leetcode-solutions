class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, vector<pair<int,int>>> graph;

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<int,int>> pq; //max heap
        pq.push({maxMoves, 0});
        vector<int> maxRemain(n, -1); // need to be -1 since 0 means visited

        while (!pq.empty()) {
            auto [remain, cur] = pq.top();
            pq.pop();

            if (maxRemain[cur] > remain) {
                continue;
            }
            maxRemain[cur] = remain;

            for (auto [next, weight] : graph[cur]) {
                if (remain >= weight + 1) {
                    pq.push({remain - weight - 1, next});
                }
            }
        }

        int res = 0;

        // add each visited node to res
        for (int i = 0; i < n; i ++) {
            // cout << maxRemain[i] << " ";
            if (maxRemain[i] >= 0) {
                res ++;
            }
        }

        // for each edge, add nodes in middle, min(weight, maxRemain[u] + maxRemain[v])
        for (auto& e : edges) {
            int start = e[0];
            int end = e[1];
            int weight = e[2];

            int startRemain = max(maxRemain[start], 0);
            int endRemain = max(maxRemain[end], 0);

            res += min(weight, startRemain + endRemain);
        }


        return res;
    }
};

// graph:
// 0: (1, 10), (2, 1)
// 1: (0, 10), (2, 2)
// 2: (0, 1), (1, 2)


// // <remain, node>
// pq: (6, 0)
// maxRemain: [0, 0, 0]