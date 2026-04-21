class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int localMin = INT_MAX;
        int localMax = INT_MIN;
        int n = arr.size();

        for (int num : arr) {
            localMin = min(localMin, num);
            localMax = max(localMax, num);
        }

        if (localMax - localMin == 0) {
            return true;
        }


        int diff = localMax - localMin;
        if (diff % (n-1) != 0) {
            return false;
        }
        int gap = diff / (n - 1);

        for (int i = 0; i < n; i ++) {
            while (arr[i] != localMin + gap * i) {
                if ((arr[i] - localMin) % gap != 0) {
                    return false;
                }
                int idx = (arr[i] - localMin) / gap;
                if (arr[i] == arr[idx]) {
                    return false;
                }
                swap(arr[i], arr[idx]);
            }
        }

        return true;
    }
};

// 1 4 5

// diff = 4
