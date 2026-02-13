class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        backtrack(res, temp, candidates, 0, target);
        return res;
    }

    bool backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int idx, int remain) {
        if (remain < 0) {
            return false;
        }

        if (remain == 0) {
            res.push_back(temp);
            return false;
        }

        for (int i = idx; i < candidates.size(); i ++) {
            if (i > idx  && candidates[i] == candidates[i-1]) {
                continue;
            }

            int num = candidates[i];
            temp.push_back(num);
            bool proceed = backtrack(res, temp, candidates, i + 1, remain - num);
            temp.pop_back();

            if (!proceed) {
                break;
            }
        }

        return true;
    }
};

// 1, 1, 6
// target = 6

