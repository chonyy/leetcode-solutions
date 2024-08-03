class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> nums;

        for(int num : target) {
            nums[num] ++;
        }
        
        for(int num : arr) {
            if(nums.count(num) == 0) {
                return false;
            }

            nums[num] --;

            if(nums[num] == 0) {
                nums.erase(num);
            }
        }

        return nums.size() == 0;
    }
};