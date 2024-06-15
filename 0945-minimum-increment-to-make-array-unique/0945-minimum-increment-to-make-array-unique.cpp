class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int size = 100000 + n + 1;
        vector<int> bucket(size); 
            
        for(int num : nums) {
            bucket[num] +=1 ;
        }
        
        int res = 0;
        for(int i = 0; i < size; i ++) {
            if(bucket[i] == 0) {
                continue;
            }
            
            int extra = bucket[i] - 1;
            bucket[i+1] += extra;
            res += extra;
        }
        
        return res;
    }
};