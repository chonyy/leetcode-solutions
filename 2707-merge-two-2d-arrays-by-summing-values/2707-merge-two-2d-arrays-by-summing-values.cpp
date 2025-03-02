class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;

        vector<vector<int>> res;

        while(i < n && j < m) {
            vector<int>& num1 = nums1[i];
            vector<int>& num2 = nums2[j];
            
            if(num1[0] == num2[0]) {
                res.push_back({num1[0], num1[1] + num2[1]});
                i ++;
                j ++;
            }
            else {
                if(num1[0] < num2[0]) {
                    res.push_back(num1);
                    i ++;
                }
                else {
                    res.push_back(num2);
                    j ++;
                }
            }
        }

        while(i < n) {
            res.push_back(nums1[i]);
            i ++;
        }

        while(j < m) {
            res.push_back(nums2[j]);
            j ++;
        }

        return res;
    }
};