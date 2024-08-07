class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> count;
        for(char c : word) {
            count[c] ++;
        }
        
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;

        for(auto& entry : count) {
            pq.push({entry.second, entry.first});
        }

        int keys = 8;
        int curNum = 0;
        int res = 0;

        while(!pq.empty()) {
            int push = curNum / keys + 1;
            char c = pq.top().second;
            pq.pop();
            curNum ++;

            // cout << c << " " << count[c] << " " << push << endl;

            res += push * count[c];
        }

        return res;
    }
};