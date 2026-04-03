class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int furthest = 0;
        queue<int> q;
        q.push(0);
        int n = s.size();

        if (s[n-1] == '1') {
            return false;
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int start = max(cur + minJump, furthest + 1);
            int end = min(cur + maxJump, n - 1);

            for (int i = start; i <= end; i++) {
                if (s[i] == '0') {
                    if (i == n - 1) return true;
                    q.push(i);
                }
            }

            furthest = max(furthest, cur + maxJump);
        }

        return false;
    }
};