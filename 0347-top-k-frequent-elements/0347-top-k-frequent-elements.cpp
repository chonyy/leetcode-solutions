class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();

        for(int num : nums) {
            m[num] ++;
        }

        vector<vector<int>> bucket(n+1);

        vector<int> res;

        // create bucket
        for(auto& entry : m) {
            bucket[entry.second].push_back(entry.first);
        }

        // get items from bucket
        for(int i = n; i > 0; i --) {
            auto& toAdd = bucket[i];
            int j = toAdd.size() - 1;

            while(k > 0 && j >= 0) {
                res.push_back(toAdd[j]);
                j --;
                k --;
            }
        }

        return res;
    }
};