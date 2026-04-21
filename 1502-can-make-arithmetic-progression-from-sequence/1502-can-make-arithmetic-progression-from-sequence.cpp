class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int localMin = INT_MAX;
        int localMax = INT_MIN;
        int n = arr.size();
        unordered_set<int> seen;

        for (int num : arr) {
            localMin = min(localMin, num);
            localMax = max(localMax, num);
            seen.insert(num);
        }

        if (seen.size() != 1 && seen.size() != n) {
            return false;
        }

        int diff = localMax - localMin;
        int gap = diff / (n - 1);

        for (int i = 0; i < n - 1; i ++) {
            localMin += gap;
            if (!seen.contains(localMin)) {
                return false;
            }
        }

        return true;
    }
};

// 1 3 5

// diff = 4
