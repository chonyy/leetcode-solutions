class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int n = arr.size();
        int r = n - 1 - (k-1);

        while (l < r) {
            int start = l + (r - l) / 2;
            int end = start + k;

            int diffStart = x - arr[start];
            int diffEnd = arr[end] - x;

            // important to not use abs
            // when both start and end are on the left side OR right have closer elements, move right
            if (diffEnd < 0 || diffStart > diffEnd) {
                l = start + 1;
            } else {
                r = start;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};

// 0 0 0 0
//     s 

// k = 2