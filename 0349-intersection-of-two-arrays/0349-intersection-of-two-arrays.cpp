class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen(nums1.begin(), nums1.end());
        unordered_set<int> unique;

        for (int num : nums2) {
            if (seen.contains(num)) {
                unique.insert(num);
            }
        }

        return vector<int>(unique.begin(), unique.end());
    }
};