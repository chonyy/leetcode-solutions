class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        
        for(int i = n-2; i >= 0; i --) {
            int p = i + 1;
            int temp = temperatures[i];
            while(p < n && temperatures[p] <= temp) {
                if(res[p] == 0)
                    p = n;
                else
                    p += res[p];
            }
            
            if(p < n)
                res[i] = p - i;
        }
        
        return res;
    }
};