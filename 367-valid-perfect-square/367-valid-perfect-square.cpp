class Solution {
public:
    bool tooBig(int num, int target) {
        return num >= target / num;
    }
    
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num / 2;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(tooBig(mid, num)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
            
        cout << l << endl;
        return l == (double)num / l;
    }
};