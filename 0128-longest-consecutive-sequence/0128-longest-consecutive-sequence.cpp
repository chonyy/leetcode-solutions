class Solution {
public:
    int find(int num, unordered_set<int>& set) {
        int cons = 1;
        
        while(set.contains(num-1)) {
            cons ++;
            num --;
        }
        
        return cons;
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int res = 0;
        
        for(int num : nums) {
            set.insert(num);
        }
        
        for(int num : nums) {
            if(set.contains(num+1)) {
                continue;
            }
            
            res = max(res, find(num, set));
        }
        
        return res;
    }
};