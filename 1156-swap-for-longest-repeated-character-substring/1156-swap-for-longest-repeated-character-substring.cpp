class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, vector<int>> positions;
        int res = 0;

        for (int i = 0; i < text.size(); i++) {
            positions[text[i]].push_back(i);
        }

        for (char c = 'a'; c <= 'z'; c++) {
            auto& idxs = positions[c];
            int n = idxs.size();
            if (n == 0) continue;

            int prev = 0;
            int cur = 1;
            int mx = 0;

            for (int i = 1; i < n; i++) {
                if (idxs[i] == idxs[i - 1] + 1) {
                    // consecutive
                    cur++;
                } else {
                    // gap — keep prev only if gap is exactly 1 char
                    prev = (idxs[i] == idxs[i - 1] + 2) ? cur : 0;
                    cur = 1;
                }

                mx = max(mx, prev + cur);
            }

            // +1 if there's a spare character to swap in
            res = max(res, mx + (n > mx ? 1 : 0));
        }

        return res;
    }
};