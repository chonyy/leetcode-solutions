class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> bucket;
        
        for(int num : nums) {
            bucket[num] ++;
        }
        
        unordered_map<int, vector<int>> freq;
        
        for(auto entry : bucket) {
            freq[entry.second].push_back(entry.first);
        }
        
        vector<int> res;
        for(int i = n; i >= 0; i --) {
            if(k <= 0) {
                break;
            }
            auto& items = freq[i];
            for(int item : items) {
                if(k <= 0) {
                    break;
                }
                res.push_back(item);
                k --;
            }
        }
        
        return res;
    }
};