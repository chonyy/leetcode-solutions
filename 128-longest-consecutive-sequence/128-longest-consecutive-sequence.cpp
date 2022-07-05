class Solution {
public:
    int find(int num, unordered_set<int>& set) {
        int count = 0;
        
        while(set.count(num)) {
            count ++;
            num --;
        }
        
        return count;
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums) {
            set.insert(num);
        }
        
        int res = 0;
        
        for(int num : nums) {
            if(set.count(num + 1)) {
                continue;
            }
            res = max(res, find(num, set));
        }
        
        return res;
    }
};