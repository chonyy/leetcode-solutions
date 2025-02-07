class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productCount;

        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                int product = nums[i] * nums[j];
                productCount[product] ++;
            }
        }

        int res = 0;

        for(auto& entry : productCount) {
            int count = entry.second;
            int combinations = count * (count - 1) / 2;
            res += combinations * 8;
        }

        return res;
    }
};