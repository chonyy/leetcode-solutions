class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        int n = nums.size();

        for(int i = 0 ; i < n; i ++) {
            char c = nums[i][i] == '1' ? '0' : '1';
            res += c;
        }

        return res;
    }
};