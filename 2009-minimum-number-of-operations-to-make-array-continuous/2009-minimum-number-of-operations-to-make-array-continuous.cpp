class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> temp;
        for (int num : nums) {
            temp.insert(num);
        }
        vector<int> s(temp.begin(), temp.end());

        int res = INT_MAX;

        for (auto start = s.begin(); start != s.end(); start ++) {
            int startIdx = start - s.begin();

            int target = *start + n - 1;
            auto end = upper_bound(s.begin(), s.end(), target);
            int endIdx = end == s.end() ? s.size() : end - s.begin();

            // cout << startIdx << " " << endIdx << endl;
            res = min(res, n - (endIdx - startIdx));
        }

        return res;
    }
};

// 1,2,3,5,6
// i.      j