class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (sum(gas) < sum(cost)) {
            return -1;
        }

        int n = gas.size();
        int total = 0;
        int res = 0;

        for (int i = 0; i < n; i ++) {
            int diff = gas[i] - cost[i];

            total += diff;
            if (total < 0) {
                res = i + 1;
                total = 0;
                continue;
            }
        }

        return res;
    }

    int sum(vector<int>& arr) {
        int sum = 0;

        for (int num : arr) {
            sum += num;
        }

        return sum;
    }
};

// brute force

// pick each idx, try circulate

// time: O(n^2)
// space: O(1)