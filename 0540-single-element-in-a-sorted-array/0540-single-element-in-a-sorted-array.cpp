class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;

        while(start < end) {
            int mid = start + (end - start) / 2;

            // find the start of the mid pair
            if(mid % 2)
                mid --;

            // this is not a pair
            // so the single element will be on the left side
            if(nums[mid] != nums[mid+1])
                end = mid;

            // there are all nice pairs at the left side
            // start looking at the next pair
            else {
                start = mid + 2;
            }
        }

        return nums[start];
    }
};