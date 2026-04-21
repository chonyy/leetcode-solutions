class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while (i < n - 1) {
            if (nums[i+1] > nums[i]) {
                i ++;
            }
            else {
                break;
            }
        }

        if (i == 0) {
            return false;
        }

        int peak = i;
        // cout << peak << endl;
        while (i < n - 1) {
            if (nums[i+1] < nums[i]) {
                i ++;
            }
            else {
                break;
            }
        }

        if (i == peak) {
            return false;
        }

        // cout << i << endl;

        bool finish = false;
        while (i < n - 1) {
            if (nums[i+1] > nums[i]) {
                i ++;
            }
            else {
                break;
            }

            if (i == n-1) {
                finish = true;
            }
        }

        return finish;
    }
};