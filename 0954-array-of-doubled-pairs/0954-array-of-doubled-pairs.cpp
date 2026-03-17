class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> count;
        
        for(int num : arr) {
            count[num] ++;
        }
        
        vector<int> keys;
        for(auto entry : count) {
            keys.push_back(entry.first);
        }
        
        auto cmp = [](int a, int b) {
            return abs(a) < abs(b);
        };
        
        sort(keys.begin(), keys.end(), cmp);
        
        for(int k : keys) {
            if(count[2 * k] < count[k])
                return false;
            count[2 * k] -= count[k];
        }
        
        return true;
    }
};