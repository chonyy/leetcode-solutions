class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }

    vector<int> mergeSort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }

        int n = nums.size();
        int mid = n / 2;
        
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < mid; i ++) {
            left.push_back(nums[i]);
        }

        for (int i = mid; i < n; i ++) {
            right.push_back(nums[i]);
        }

        auto leftSorted = mergeSort(left);
        auto rightSorted = mergeSort(right);

        return merge(leftSorted, rightSorted);
    }

    vector<int> merge(vector<int>& left, vector<int>& right) {
        vector<int> res;

        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                res.push_back(left[i]);
                i ++;
            }
            else {
                res.push_back(right[j]);
                j ++;
            }
        }

        while (i < left.size()) {
            res.push_back(left[i]);
            i ++;
        }

        while (j < right.size()) {
            res.push_back(right[j]);
            j ++;
        }

        return res;
    }
};