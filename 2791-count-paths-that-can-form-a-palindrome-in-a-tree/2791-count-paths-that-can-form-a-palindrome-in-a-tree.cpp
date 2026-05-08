class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> mask(n);
        unordered_map<int, vector<int>> graph;

        // build graph
        for (int i = 0; i < n ; i++) {
            if (parent[i] == -1) {
                continue;
            }

            graph[parent[i]].push_back(i);
        }

        // dfs and count freq in mask
        getMask(graph, 0, 0, s, mask);

        // loop n
        // res += count[mask[i]]
        // diff by one bit
        // set count
        unordered_map<int, int> maskCount;
        long long res = 0;
        for (int i = 0 ; i < n; i ++) {
            res += maskCount[mask[i]];

            for (int j = 0; j < 26; j ++) {
                int diffBit = 1 << j;
                res += maskCount[mask[i] ^ diffBit];
            }

            maskCount[mask[i]] ++;
        }

        return res;
    }

    void getMask(unordered_map<int, vector<int>>& graph, int node, int curMask, string& s, vector<int>& mask) {
        // set mask
        mask[node] = curMask;

        // visit neighbor
        for (int nei : graph[node]) {
            char c = s[nei];
            int newMask = curMask ^ (1 << (c - 'a'));
            getMask(graph, nei, newMask, s, mask);
        }
    }
};