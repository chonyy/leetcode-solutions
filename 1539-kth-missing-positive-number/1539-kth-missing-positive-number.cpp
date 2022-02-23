class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0; 
        int r = n;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int num = arr[mid];
            if(num - mid - 1 >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        int point = l - 1;
        if(point < 0)
            return k;
        
        int missing = arr[point] - point - 1;
        cout << missing << endl;
        
        return arr[point] + k - missing;
    }
};


// 2 3 4 7 11
    
// 1 1 1 3 6