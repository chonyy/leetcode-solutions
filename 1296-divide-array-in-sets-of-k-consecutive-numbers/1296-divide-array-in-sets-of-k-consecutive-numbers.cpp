class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;

        map<int, int> count;
        for (int num : nums) count[num]++;

        for (auto& [num, _] : count) {
            int freq = count[num];  // copy, not reference
            if (freq == 0) continue;
            for (int i = 0; i < k; i++) {
                if (count[num + i] < freq) return false;
                count[num + i] -= freq;
            }
        }

        return true;
    }
};