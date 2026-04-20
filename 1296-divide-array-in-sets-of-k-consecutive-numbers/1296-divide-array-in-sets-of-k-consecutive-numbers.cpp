class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int> count;

        for (int num : nums) {
            count[num] ++;
        }

        for (int num : nums) {
            if (count[num] == 0) {
                continue;
            }

            // while still have num
            // - find smallest
            // - try consume k from smallest

            while (count[num]) {
                int smallest = num;
                // cout << "small " << smallest << endl;
                while (count[smallest - 1]) {
                    smallest --;
                }

                if (consume(count, smallest, k) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool consume(unordered_map<int,int>& count, int smallest, int k) {
        for (int i = 0; i < k; i ++) {
            if (count[smallest + i] == 0) {
                // cout << "fail " << smallest + i << endl;
                return false;
            }
            count[smallest + i] --;
        }

        return true;
    }
};

// 4 3 2 1 2 3 1 2 3