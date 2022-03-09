class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int drop = 0;
        int noDrop = arr[0];
        int ans = arr[0];
        int n = arr.size();
        
        for(int i = 1; i < n; i ++) {
            drop = max(drop + arr[i], noDrop);
            noDrop = max(noDrop + arr[i], arr[i]);
            ans = max(ans, max(drop, noDrop));
        }
        
        return ans;
    }
};