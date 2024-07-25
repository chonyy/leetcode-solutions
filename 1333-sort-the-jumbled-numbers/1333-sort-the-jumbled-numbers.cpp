class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        if(a.first == b.first)
            return a.second < b.second;

        return a.first < b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> pairs;
        vector<int> origNums = nums;

        int n = nums.size();

        for(int i =0 ; i < n; i ++) {
            pairs.push_back({toMapped(mapping, nums[i]), i});
        }
        sort(pairs.begin(), pairs.end(), cmp);

        vector<int> res;

        for(auto& pair : pairs) {
            res.push_back(origNums[pair.second]);
        }

        return res;
    }

    int toMapped(vector<int>& mapping, int num) {
        int res = 0;
        int mult = 1;

        if(num == 0) {
            return mapping[0];
        }

        while(num) {
            int curNum = num % 10;

            res += mapping[curNum] * mult;

            num = num / 10;
            mult *= 10;
        }

        // cout << res << endl;
        return res;
    }
};