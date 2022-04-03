class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int toSwap = -1;
        int n = nums.size();
        
        for(int i = n-2; i >= 0; i --) {
            if(nums[i] < nums[i+1]) {
                toSwap = i;
                break;
            }
        }
        
        if(toSwap == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int nextLarger = -1;
        for(int i = n-1; i > toSwap; i --) {
            if(nums[i] > nums[toSwap]) {
                nextLarger = i;
                break;
            }
        }
        
        swap(nums[toSwap], nums[nextLarger]);
        reverse(nums.begin() + toSwap + 1, nums.end());        
    }
};



//  1 5 3 2
     
//  2 5 3 1
//  2 1 3 5
     
     
//  1 2 3 4
     
//  1 5 4 3 2
//  2 1 3 4 5
//  2 1 3 5 4
     
 // 2 3 1
     
     