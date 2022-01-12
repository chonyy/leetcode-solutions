class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int curSum, int idx) {
        if(curSum == target) {
            res.push_back(temp);
            return;
        }
        
        if(curSum > target) {
            return;
        }
        
        for(int i = idx; i < candidates.size(); i ++) {
            temp.push_back(candidates[i]);
            backtrack(res, temp, candidates, target, curSum + candidates[i], i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, temp, candidates, target, 0, 0);
        
        return res;
    }
};