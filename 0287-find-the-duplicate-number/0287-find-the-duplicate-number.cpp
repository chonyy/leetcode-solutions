class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int slow2 = 0;
        while(slow2 != slow) {
            slow2 = nums[slow2];
            slow = nums[slow];
        }

        return slow;
    }
};

// 1
// 3
// 4
// 2
// 2

// 1->3->2
// 4->2
// 2->4
// 2->4