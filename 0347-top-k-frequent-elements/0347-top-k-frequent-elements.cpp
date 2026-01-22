class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;

        for (int num : nums) {
            count[num] ++;
        }

        int n = nums.size();
        unordered_map<int, vector<int>> freqMap;
        for (auto& entry : count) {
            freqMap[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = n; i >= 0; i --) {
            if (k <= 0) {
                break;
            }

            vector<int>& toAdd = freqMap[i];
            res.insert(res.end(), toAdd.begin(), toAdd.end());
            k -= toAdd.size();
        }

        return res;
    }
};