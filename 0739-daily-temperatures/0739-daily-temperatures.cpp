class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> prevTemp;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i ++) {
            int temp = temperatures[i];
            while (!prevTemp.empty() && prevTemp.top().second < temp) {
                res[prevTemp.top().first] = i - prevTemp.top().first;
                prevTemp.pop();
            }
            prevTemp.push({i, temp});
        }

        return res;
    }
};