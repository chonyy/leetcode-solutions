class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = pow(10, 9) + 7;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i ++) {
            pq.push({nums[i], i});
        }

        int res = 0;
        for(int i = 0; i < right; i ++) {
            auto& cur = pq.top();
            int curSum = cur.first;
            int curIdx = cur.second;
            pq.pop();

            if(curIdx+1 < n)
                pq.push({curSum + nums[curIdx+1], curIdx+1});

            if(i >= left - 1) {
                // cout << i << " " << curSum << endl;
                res = (res + curSum) % mod;
                // cout << res << endl;
            }
        }

        return res;
    }
};