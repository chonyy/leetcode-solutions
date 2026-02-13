class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> posDiags;
    unordered_set<int> negDiags;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> res;

        solve(res, temp, n, 0);

        return res;
    }

    void solve(vector<vector<string>>& res, vector<string>& temp, int n, int r) {
        if (r == n) {
            res.push_back(temp);
            return;
        }

        for (int c = 0; c < n; c ++) {
            if (cols.contains(c)) {
                continue;
            }
            int posDiag = r + c;
            int negDiag = r - c;
            if (posDiags.contains(posDiag)) {
                continue;
            }
            if (negDiags.contains(negDiag)) {
                continue;
            }

            cols.insert(c);
            posDiags.insert(posDiag);
            negDiags.insert(negDiag);
            temp[r][c] = 'Q';
            
            solve(res, temp, n, r + 1);

            cols.erase(c);
            posDiags.erase(posDiag);
            negDiags.erase(negDiag);
            temp[r][c] = '.';
        }
    }
};
