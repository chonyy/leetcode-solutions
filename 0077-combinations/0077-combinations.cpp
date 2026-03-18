class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;

        getCombination(1, n, k, temp, res);

        return res;
    }

    void getCombination(int cur, int n, int remain, vector<int>& temp, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = cur; i <= n; i ++) {
            // cout << i << endl;
            temp.push_back(i);
            getCombination(i+1, n, remain-1, temp, res);
            temp.pop_back();
        }
    }
};