class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<int> res;
        
        for(int num : nums) {
            freqMap[num] ++;
        }
        
        unordered_map<int, vector<int>> bucket;
        for(auto& [num, freq] : freqMap) {
            bucket[freq].push_back(num);
        }
        
        // counting sort
        for(int i = nums.size(); i >= 0; i --) {
            if(!bucket.contains(i)) {
                continue;
            }
            
            auto& freqNums = bucket[i];
            int m = freqNums.size() - 1;
            
            while(k > 0 && m >= 0) {
                res.push_back(freqNums[m]);
                    
                m --;
                k --;
            }
        }
        
        return res;
    }
};