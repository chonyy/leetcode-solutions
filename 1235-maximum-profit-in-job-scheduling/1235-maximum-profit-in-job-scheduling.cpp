class Solution {
public:
    unordered_map<int,int> mem;

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();

        for (int i = 0; i < n; i ++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        for (int i = 0; i < n; i ++) {
            startTime[i] = jobs[i][0];
        }

        return findMax(jobs, startTime, 0);
    }

    int findMax(vector<vector<int>>& jobs, vector<int>& startTime, int idx) {
        if (idx >= jobs.size()) {
            return 0;
        }

        if (mem.contains(idx)) {
            return mem[idx];
        }

        int notTake = findMax(jobs, startTime, idx + 1);

        // take
        int take = jobs[idx][2];
        int target = jobs[idx][1];
        auto it = lower_bound(startTime.begin(), startTime.end(), target);

        if (it != startTime.end()) {
            take += findMax(jobs, startTime, it - startTime.begin());
        }

        int res = max(take, notTake);
        mem[idx] = res;
        return res;
    }
};