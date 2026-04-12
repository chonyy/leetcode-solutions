class NumArray {
public:
    vector<int> prefix;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix = vector<int>(n+1);
        prefix[0] = 0;
        
        for(int i = 1; i <= n; i ++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */