class Solution {
public:
    bool solve(int idx, vector<int>& matchsticks, vector<int>& sideLen, int target) {
        if(idx == matchsticks.size())
            return sideLen[0] == sideLen[1] && sideLen[1] == sideLen[2] && sideLen[2] == sideLen[3];
        
        for(int i = 0; i < 4; i ++) {
            if(sideLen[i] + matchsticks[idx] > target)
                continue;
            
            int j;
            for(j = i+1; j < 4; j ++)
                if(sideLen[j] == sideLen[i])
                    break;
            if(j != 4)
                continue;
            
            sideLen[i] += matchsticks[idx];
            if(solve(idx+1, matchsticks, sideLen, target))
                return true;
            sideLen[i] -= matchsticks[idx];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        vector<int> sideLen(4, 0);
        int sum = 0;
        for(int m : matchsticks) {
            sum += m;
        }
        if(sum % 4 != 0)
            return false;
        
        return solve(0, matchsticks, sideLen, sum/4);
    }
};