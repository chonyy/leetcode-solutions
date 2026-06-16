class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> count;
        int n = nums.size();
        vector<long long> res;
        priority_queue<pair<long long, int>> mostFreq;

        for (int i = 0; i < n; i ++) {
            count[nums[i]] += freq[i];
            mostFreq.push({count[nums[i]], nums[i]});
            
            while (!mostFreq.empty()) {
                auto top = mostFreq.top();
                if (count[top.second] == top.first) {
                    break;
                }

                mostFreq.pop();
            }

            res.push_back(mostFreq.top().first);
        }

        return res;
    }
};