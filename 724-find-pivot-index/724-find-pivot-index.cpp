class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        
        for(int i = 1; i <= n; i ++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        for(int i = 0; i < n; i ++) {
            if(prefix[n] - prefix[i+1] == prefix[i] - prefix[0])
                return i;
        }
        
        return -1;
    }
};

//   1 7 3  6  5  6
// 0 1 8 11 17 22 28
// 0 1 2 3  4