class Solution {
public:
    int sum = 0;
    vector<int> prefix = {-1};
    Solution(vector<int>& w) {
        for (int num : w) {
            sum += num;
            prefix.push_back(prefix.back() + num);
        }
    }
    
    int pickIndex() {
        int pick = rand() % sum;
        auto it = lower_bound(prefix.begin(), prefix.end(), pick);
        return it - prefix.begin() - 1;;
    }

    // 1, 2, 2

    // 0, 2, 4

    // rand() % sum 

    // 0 ~ 4 

    // 0: 1
    // 2: 3
    // 3: 3
    // 4: 5
    // 5: 5
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */