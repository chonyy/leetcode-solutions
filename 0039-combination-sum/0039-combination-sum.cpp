class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;

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
            int num = candidates[i];
            temp.push_back(num);
            bool proceed = backtrack(res, temp, candidates, i, remain - num);
            temp.pop_back();

            if (!proceed) {
                break;
            }
        }

        return true;
    }
};