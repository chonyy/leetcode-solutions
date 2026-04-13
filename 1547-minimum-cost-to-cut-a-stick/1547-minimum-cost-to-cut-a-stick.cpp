class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> cache(m, vector<int>(m, -1));

        return solve(0, m - 1, cache, cuts);
    }

    int solve(int l, int r, vector<vector<int>>& cache, vector<int>& cuts) {
        if (r - l <= 1) return 0;
        if (cache[l][r] != -1) return cache[l][r];

        int res = INT_MAX;
        for (int i = l + 1; i < r; i++) {
            res = min(res, solve(l, i, cache, cuts) + solve(i, r, cache, cuts));
        }

        return cache[l][r] = res + cuts[r] - cuts[l];
    }
};