class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void p(vector<int>& nums, int depth, vector<bool>& used) {
        if(depth == used.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < nums.size(); i ++) {
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
                        
            if(used[i])
                continue;
            
            used[i] = true;
            temp.push_back(nums[i]);
            p(nums, depth+1, used);
            temp.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> used(n, false);
        p(nums, 0, used);
        
        return res;
    }
};