class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq;
        queue<int> rq;
        int n = senate.size();

        for (int i = 0; i < n; i ++) {
            char c = senate[i];
            if (c == 'R') {
                rq.push(i);
            }
            else {
                dq.push(i);
            }
        }

        while (!dq.empty() && !rq.empty()) {
            int dIdx = dq.front();
            dq.pop();
            int rIdx = rq.front();
            rq.pop();

            if (dIdx < rIdx) {
                dq.push(dIdx + n);
            }
            else {
                rq.push(rIdx + n);
            }
        }

        return dq.empty() ? "Radiant" : "Dire";
    }
};