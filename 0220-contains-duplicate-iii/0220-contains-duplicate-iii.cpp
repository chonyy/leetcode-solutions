class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> seen;
        int n = nums.size();

        for (int i = 0; i < n; i ++) {
            int num = nums[i];

            // check next
            auto next = seen.upper_bound(num);
            if (next != seen.end()) {
                if (abs(*next - num) <= valueDiff) {
                    return true;
                }
            }

            // check prev
            if (next != seen.begin()) {
                auto pre = prev(next);
                if (abs(*pre - num) <= valueDiff) {
                    return true;
                }
            }

            // insert
            seen.insert(num);

            // erase if larger than k
            if (seen.size() > indexDiff) {
                seen.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};


// 6,5,4,5,8,10
//         r
//     l

// deque: 4, 5, 8

// valueDiff = 3
// indexDiff = 2