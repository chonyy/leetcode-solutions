class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> changes = {0, 0, 0};

        for (int b : bills) {
            if (b == 5) {
                changes[0] ++;
            }
            if (b == 10) {
                if (changes[0] == 0) {
                    return false;
                }
                changes[0] --;
                changes[1] ++;
            }
            if (b == 20) {
                // return 10 + 5
                // return 5 + 5 + 5
                if (changes[1] && changes[0]) {
                    changes[1] --;
                    changes[0] --;
                }
                else if (changes[0] >= 3) {
                    changes[0] -= 3;
                }
                else {
                    return false;
                }

                changes[2] ++;
            }
        }

        return true;
    }
};