class Solution {
public:
    vector<int> prefixSum;
    int sum = 0;
    Solution(vector<int>& w) {
        int n = w.size();
        prefixSum = w;
        for(int i = 1; i < n; i ++) {
            prefixSum[i] += prefixSum[i-1];
        }
        sum = prefixSum[n-1];
    }
    
    int pickIndex() {
        int random = rand() % sum;
        auto it = upper_bound(prefixSum.begin(), prefixSum.end(), random);
        return it - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// 1 4