class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> curLen;
        int res = 0;

        for (int num : nums) {
            if (curLen[num]) {
                continue;
            }

            curLen[num] = curLen[num-1] + curLen[num+1] + 1;
            curLen[num - curLen[num-1]] = curLen[num];
            curLen[num + curLen[num+1]] = curLen[num];

            // cout << num << " " << curLen[num] << endl;

            res = max(res, curLen[num]);   
        }

        return res;
    }
};