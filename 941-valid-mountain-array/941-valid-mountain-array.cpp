class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        
        while(l < n-1 && arr[l] < arr[l+1]) {
            l ++;
        }
        
        while(r > 0 && arr[r] < arr[r-1]) {
            r --;
        }
        
        return l > 0 && r < n-1 && l == r;
    }
};