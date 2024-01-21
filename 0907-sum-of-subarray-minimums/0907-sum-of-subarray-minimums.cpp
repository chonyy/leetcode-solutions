class Solution {
public:
    int n;
    void getLp(vector<int>& lp, vector<int>& arr) {
        stack<int> stk;
        
        for(int i = 0; i < n; i ++) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if(!stk.empty()) {
                lp[i] = stk.top();
            }
            stk.push(i);
        }
    }
    
    void getNp(vector<int>& np, vector<int>& arr) {
        stack<int> stk;
        
        for(int i = 0; i < n; i ++) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                // cout << i << " pop " << stk.top() << endl;
                np[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        n = arr.size();
        vector<int> lp(n, -1);
        vector<int> np(n, n);
        
        getLp(lp, arr);
        getNp(np, arr);
        int ans = 0;
        
        for(int i = 0; i < n; i ++) {
            int lDist = (i - lp[i]) % mod;
            int rDist = (np[i] - i) % mod;
            // cout << lp[i] << " " << np[i] << endl;
            // cout << lDist << " " << rDist << endl;
            // cout << endl;
            ans = (ans + (long)arr[i] * lDist * rDist) % mod;
        }
        
        return ans;
    }
};