class Solution {
public:
    int sum = 0;
    vector<int> prefix;
    
    Solution(vector<int>& w) {
        prefix.push_back(0);
        for(int i = 1; i <= w.size(); i ++) {
            prefix.push_back(prefix[i-1] + w[i-1]);
            sum += w[i-1];
        }
    }
    
    int pickIndex() {
        int pick = rand() % sum;
        auto it = upper_bound(prefix.begin(), prefix.end(), pick);
        return it - prefix.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */