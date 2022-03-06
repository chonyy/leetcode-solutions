class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        map<int, int> count;
        int n = changed.size();
        if(n % 2)
            return {};
        
        for(int num : changed) {
            count[num] ++;
        }
        
        for(auto& entry : count) {
            if(entry.second == 0)
                continue;
            
            int x = entry.first;
            // cout << x << endl;
            if(count[2*x] < count[x])
                return {};
            for(int i = 0; i < entry.second; i ++) {
                res.push_back(x);
                count[2*x] --;
            }
        }
        
        return res;
    }
};