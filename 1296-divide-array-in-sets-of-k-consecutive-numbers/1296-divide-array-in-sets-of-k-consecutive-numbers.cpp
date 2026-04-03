class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }

        unordered_map<int,int> count;
        for (int num : nums) {
            count[num] ++;
        }

        for (int num : nums) {
            if (count[num] == 0) {
                continue;
            }

            while (count[num]) {
                int smallest = num;
                while (count[smallest-1]) {
                    smallest --;
                }

                // cout << "small " << smallest << endl;
                // try to get k consecutive and update count
                for (int i = 0; i < k; i ++) {
                    int target = smallest + i;

                    // cout << "target " << target << endl;
                    // cout << count[target] << endl;
                    if (count[target] == 0) {
                        return false;
                    }
                    count[target] --;
                }
            }
        }

        return true;
    }
};