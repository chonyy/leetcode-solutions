class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int res = 0;

        for (int i = 0; i < n; i ++) {
            if (i == n-1 || timeSeries[i+1] >= timeSeries[i] + duration) {
                res += duration;
            }
            else {
                res += timeSeries[i+1] - timeSeries[i];
            }
        }

        return res;
    }
};

// [1, 4]


// prev = 
// duration = 2


// 1, 5
// duration 8

// 4 + 8


// for each t, check next element
// if last or next >= t + duration
//     add full duration
// else
//     add next - t

// 1, 3
// duration = 2