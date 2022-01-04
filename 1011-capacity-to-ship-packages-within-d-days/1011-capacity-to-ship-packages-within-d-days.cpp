class Solution {
public:
    bool workable(vector<int>& weights, int cap, int days) {
        int need = 1;
        int curCap = 0;
        
        for(int wei : weights) {
            curCap += wei;
            
            if(wei > cap)
                return false;
            
            if(curCap > cap) {
                need ++;
                curCap = wei;
            }
        }
        
        cout << cap << " " << need << endl;
        return need <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 3 * 1e8;
        
        while(l < r) {
            int mid = l + (r-l) / 2;
            if(workable(weights, mid, days)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};