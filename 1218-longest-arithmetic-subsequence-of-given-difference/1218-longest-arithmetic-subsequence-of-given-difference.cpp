class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> count;
        int ans = 0;
        
        for(int num : arr) {
            count[num] = count[num - difference] + 1;
            ans = max(ans, count[num]);
        }
        
        return ans;
    }
};