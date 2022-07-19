class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> t(numRows);
    for(int i = 0; i < numRows; i ++) {
        t[i].resize(i + 1);
        t[i][0] = t[i][i] = 1;
        for(int j = 1; j < i; j ++) {
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
        }
    }
    return t;
}
};