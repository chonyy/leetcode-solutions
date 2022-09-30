class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0;
        int r = n - k;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int val = arr[mid];
            int next = arr[mid + k];
            
            if(next - x < x - val) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};