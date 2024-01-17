class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> occur;
        
        for(int num : arr) {
            m[num] ++;
        }
        
        for(auto& [num, count] : m) {
            if(occur.contains(count)) {
                return false;
            }
            
            occur.insert(count);
        }
        
        return true;
    }
};