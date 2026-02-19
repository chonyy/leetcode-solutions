class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, vector<string>> graph;

        // build graph
        for (auto& t : tickets) {
            graph[t[0]].push_back(t[1]);
        }

        // sort decreasing order
        for (auto& entry : graph) {
            vector<string>& destinations = entry.second;
            sort(destinations.rbegin(), destinations.rend());
        }

        // dfs
        string start = "JFK";
        dfs(res, graph, start);

        // reverse res
        reverse(res.begin(), res.end());

        return res;
    }

    // Hierholzer's Algorithm 
    void dfs(vector<string>& res, unordered_map<string,vector<string>>& graph, string& src) {
        // explore
        // loop through all neighbors and run dfs

        // after looping, add to res
        while (!graph[src].empty()) {
            string dest = graph[src].back();
            graph[src].pop_back();

            dfs(res, graph, dest);
        }

        res.push_back(src);
    }
};