class Solution {
private:
    void merge_sort(int start, int end, vector<pair<int, int>>& nums, vector<int>& indices, vector<pair<int, int>>& temp) {
        if(start >= end)
            return;
        
        int mid = start + (end - start) / 2;
        
        merge_sort(start, mid, nums, indices, temp);
        merge_sort(mid + 1, end, nums, indices, temp);
        
        int left = start, right = mid + 1;
        int idx = start;
        int nRightLessThanLeft = 0;
        while(left <= mid and right <= end) {
            if(nums[left] < nums[right]) {
                indices[nums[left].second] += nRightLessThanLeft;
                temp[idx++] = nums[left++];
            } else if(nums[left] > nums[right]) {
                temp[idx++] = nums[right++];
                nRightLessThanLeft++;
            } else
                left++, right++;
        }
        
        while(left <= mid) {
            indices[nums[left].second] += nRightLessThanLeft;
            temp[idx++] = nums[left++];
        }
        
        while(right <= end)
            temp[idx++] = nums[right++];
        
        for(int i=start; i<=end; i++)
            nums[i] = temp[i];
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> new_nums; // {num, original_idx}
        vector<int> indices(n, 0);
        vector<pair<int, int>> temp;
        
        for(int i=0; i<n; i++) {
            new_nums.push_back({nums[i], i});
            temp.push_back({nums[i], i});
        }
        
        merge_sort(0, n-1, new_nums, indices, temp);
        
        return indices;
    }
};