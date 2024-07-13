class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int, int> m;
        int n = positions.size();

        for(int i = 0; i < n; i ++) {
            m[positions[i]] = i;
        }

        stack<int> stk;
        for(auto& entry : m) {
            int i = entry.second;

            while(!stk.empty() && directions[stk.top()] == 'R' && directions[i] == 'L' && healths[i]) {
                cout << stk.top() << " collide with " << i << endl;
                if(healths[stk.top()] == healths[i]) {
                    healths[stk.top()] = 0;
                    healths[i] = 0;
                    stk.pop();
                }
                else if(healths[stk.top()] > healths[i]) {
                    healths[stk.top()] --;
                    healths[i] = 0;
                }
                else {
                    healths[stk.top()] = 0;
                    healths[i] --;
                    stk.pop();
                }
            }

            if(healths[i]) {
                stk.push(i);
            }
        }


        vector<int> res;
        for(int i = 0; i < n; i ++) {
            if(healths[i]) {
                res.push_back(healths[i]);
            }
        }

        return res;
    }
};