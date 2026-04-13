class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        unordered_map<int,unordered_map<int, int>> cache;

        return solve(0, n, cache, cuts);
    }

    int solve(int l, int r, unordered_map<int,unordered_map<int, int>>& cache, vector<int>& cuts) {
        if (l == r) {
            return 0;
        }

        if (cache.contains(l) && cache[l].contains(r)) {
            return cache[l][r];
        }

        int res = INT_MAX;

        for (int c : cuts) {
            if (c <= l || c >= r) {
                continue;
            }

            int cost = solve(l, c, cache, cuts) + solve(c, r, cache, cuts);
            res = min(res, cost);
        }
        
        if (res == INT_MAX) {
            cache[l][r] = 0;
            return 0;
        }

        res += r - l;

        cache[l][r] = res;
        return res;
    }
};