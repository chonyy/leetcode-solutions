class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26);
        
        for(char c : s) {
            count[c - 'a'] ++;
        }
        sort(count.begin(), count.end(), greater<int>());
        
        int ans = 0;
        int curMax = s.size();
        
        for(int i = 0; i < count.size(); i ++) {
            if(count[i] == 0) {
                break;
            }
            
            if(count[i] >= curMax) {
                ans += count[i] - curMax;
                count[i] = curMax;
            }
            curMax = max(count[i] - 1, 0);
        }
        
        return ans;
    }
};