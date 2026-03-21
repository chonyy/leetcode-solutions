class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) {
            return 1;
        }

        vector<int> trustt(n+1, 0);
        vector<int> trusted(n+1, 0);

        for (auto& t : trust) {
            trustt[t[0]] ++;
            trusted[t[1]] ++;
        }

        for (int i = 1; i <= n; i ++) {
            if (trustt[i] == 0 && trusted[i] == n-1) {
                return i;
            }
        }

        return -1;
    }
};