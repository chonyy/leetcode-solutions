class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int up = 1;
        int down = 1;
        int n = arr.size();

        int res = 1;

        for (int i = 1; i < n; i ++) {
            if (arr[i] == arr[i-1]) {
                up = 1;
                down = 1;
            }
            else if (arr[i] > arr[i-1]) {
                up = down + 1;
                down = 1;
            }
            else {
                down = up + 1;
                up = 1;
            } 

            res = max({res, up, down});
        }

        return res;
    }
};

// 9,4,2,10,7,8,8,1,9
//                  i

// 1 1 1 3 1 5 1 1 3
// 1 2 2 1 4 1 1 2 1

// up
// down